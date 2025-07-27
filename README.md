
# RCX Arduino Library

Este repositório contém a biblioteca **RCX**, desenvolvida para facilitar a aplicação didática no controle de motores e sensores em projetos Arduino com arquitetura semelhante ao LEGO RCX.  

## 🚀 Instalação Rápida

### 1. **Download**
- Baixe o `.zip` em "releases" e extraia.

### 2. **Execute o Instalador**
- Execute o arquivo `installer.exe`.
- Ele irá copiar automaticamente a pasta `RCX/` para o seguinte diretório:
  ```
  C:\Users\<seu_nome_de_usuário>\Documents\Arduino\libraries\RCX
  ```
- A pasta `RCX` precisa estar **na mesma pasta que o instalador** para funcionar corretamente.

---

## 📚 Como Usar no Arduino

Inclua a biblioteca RCX no seu sketch:

```cpp
#include <RCX.h>

RCX rcx;

void setup() 
{
  rcx.begin();
}

void loop() 
{
  rcx.Spin_Motor("A",1,100);
  rcx.Spin_Motor("B",1,100);
  rcx.Spin_Motor("C",1,100);
  float sensor1 = rcx.Read_Sensor(1);
  float sensor2 = rcx.Read_Sensor(2);
  float sensor3 = rcx.Read_Sensor(3);
}
```
Por padrão estão sendo usados pinos:
 - Motor_A_1 `3`
 - Motor_A_2 `5`

 - Motor_B_1 `6`
 - Motor_B_2 `9`

 - Motor_C_1 `10`
 - Motor_C_2 `11`

 - Sensor_1 `4`
 - Sensor_2 `7`
 - Sensor_3 `8`

Então faça as ligações no arduino levando isso em consideração.
---

## ⚙️ RCX - Métodos Disponíveis

### `begin()`
Inicializa os pinos dos motores e sensores.

### `Spin_Motor(char name, int direction, int intensity)`
Controla um motor:
- `name`: 'A', 'B' ou 'C'
- `direction`: `1` (horário) ou `2` (anti-horário)
- `intensity`: de 0 a 100 (%)

### `Read_Sensor(int sensorNum)`
Lê um sensor:
- `sensorNum`: `1`, `2` ou `3`
- Retorna um valor normalizado entre 0 e 1

---

## 🧑‍💻 Desenvolvedor

Gabriel Spressola Ziviani – [@Slayer_Nefarox](https://github.com/Slayer-Nefarox)

---

## 🛠 Requisitos

- Arduino IDE
- Windows 10 ou superior
- Permissões de escrita na pasta `Documents\Arduino\libraries`

---

## 📝 Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
