#include <windows.h>
#include <stdio.h>
#include <string.h>

// Copia recursivamente uma pasta
void CopyFolder(const char* source, const char* destination) {
    WIN32_FIND_DATA findData;
    char searchPath[MAX_PATH];
    char srcPath[MAX_PATH];
    char destPath[MAX_PATH];

    snprintf(searchPath, MAX_PATH, "%s\\*", source);
    HANDLE hFind = FindFirstFile(searchPath, &findData);
    if (hFind == INVALID_HANDLE_VALUE) return;

    CreateDirectory(destination, NULL);

    do {
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0)
            continue;

        snprintf(srcPath, MAX_PATH, "%s\\%s", source, findData.cFileName);
        snprintf(destPath, MAX_PATH, "%s\\%s", destination, findData.cFileName);

        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            CopyFolder(srcPath, destPath);
        } else {
            CopyFile(srcPath, destPath, FALSE);
        }
    } while (FindNextFile(hFind, &findData));

    FindClose(hFind);
}

// Remove o nome do executável do caminho
void RemoveExecutableFromPath(char* path) {
    for (int i = strlen(path) - 1; i >= 0; --i) {
        if (path[i] == '\\') {
            path[i] = '\0';  // Termina a string no último '\'
            break;
        }
    }
}

int main() {
    char exePath[MAX_PATH];
    char rcxSource[MAX_PATH];
    char username[256];
    char arduinoLibPath[MAX_PATH];
    char rcxDest[MAX_PATH];

    printf("RCX Installer by @Slayer_Nefarox\n");

    // Obtém o caminho completo do executável
    if (!GetModuleFileName(NULL, exePath, MAX_PATH)) {
        printf("Erro ao obter o caminho do executável.\n");
        return 1;
    }

    // Remove o nome do executável do caminho
    RemoveExecutableFromPath(exePath);

    // Monta o caminho da pasta RCX (na mesma pasta do exe)
    snprintf(rcxSource, MAX_PATH, "%s\\RCX", exePath);

    // Verifica se a pasta RCX existe
    DWORD attrs = GetFileAttributes(rcxSource);
    if (attrs == INVALID_FILE_ATTRIBUTES || !(attrs & FILE_ATTRIBUTE_DIRECTORY)) {
        printf("A pasta 'RCX' não foi encontrada no mesmo diretório do executável.\n");
        return 1;
    }

    // Obtém o nome do usuário
    DWORD len = GetEnvironmentVariable("USERNAME", username, sizeof(username));
    if (len == 0 || len > sizeof(username)) {
        printf("Erro ao obter nome do usuário.\n");
        return 1;
    }

    // Monta caminho final: C:\Users\<user>\Documents\Arduino\libraries
    snprintf(arduinoLibPath, MAX_PATH, "C:\\Users\\%s\\Documents\\Arduino\\libraries", username);
    CreateDirectory(arduinoLibPath, NULL);  // Garante que a pasta existe

    // Destino final: ...\libraries\RCX
    snprintf(rcxDest, MAX_PATH, "%s\\RCX", arduinoLibPath);

    // Copia a pasta
    printf("Copiando RCX de:\n%s\npara:\n%s\n", rcxSource, rcxDest);
    CopyFolder(rcxSource, rcxDest);
    printf("Instalação concluída com sucesso!\n");

    system("pause");
    return 0;
}
