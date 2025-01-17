# Projeto: Controle de Pinos GPIO com Teclado Matricial 4x4

Este projeto tem como objetivo implementar o controle de pinos GPIO utilizando um teclado matricial 4x4 e um microcontrolador Raspberry Pi Pico W. O sistema irá controlar 3 LEDs RGB, um buzzer e exibir informações em um display LCD1602, acionados pelas teclas pressionadas no teclado matricial. O código é desenvolvido na linguagem C utilizando o Pico SDK e simulado com o simulador de eletrônica online Wokwi.

## Vídeo da Prática

Segue o link do vídeo dos resultados obtidos durante a simulação:

[Vídeo de Simulação](https://www.youtube.com.br/)

---

## Tabela de Conteúdos

- [Projeto: Controle de Pinos GPIO com Teclado Matricial 4x4](#projeto-controle-de-pinos-gpio-com-teclado-matricial-4x4)
  - [Vídeo da Prática](#vídeo-da-prática)
  - [Tabela de Conteúdos](#tabela-de-conteúdos)
  - [Estrutura do Repositório](#estrutura-do-repositório)
  - [Como Rodar o Projeto](#como-rodar-o-projeto)
  - [Simulação no Wokwi:](#simulação-no-wokwi)
  - [Delegação de Tarefas](#delegação-de-tarefas)
  - [Prazos e Datas Importantes](#prazos-e-datas-importantes)

## Estrutura do Repositório

A estrutura do repositório é organizada da seguinte forma:

````
/projeto
│
├── /src               # Código-fonte do projeto
│   ├── main.c         # Arquivo principal
│   ├── leds_buzzer.c  # Funções de controle dos LEDs e buzzer
│   ├── lcd.c          # Funções para controle do display LCD1602
│   ├── teclado.c      # Funções de controle do teclado matricial
│   ├── gpio.c         # Funções auxiliares de controle dos pinos GPIO
│
├── /include           # Cabeçalhos (.h)
│   ├── leds_buzzer.h  # Definições dos LEDs e buzzer
│   ├── lcd.h          # Definições do display LCD1602
│   ├── teclado.h      # Definições do teclado matricial
│   ├── gpio.h         # Definições para GPIO
│
├── README.md          # Arquivo com instruções de uso do projeto
├── CMakeLists.txt     # Arquivo de configuração do CMake
├── wokwi.toml         # Arquivo de configuração do simulador Wokwi
└── Makefile           # Makefile para construção do projeto

````


## Como Rodar o Projeto

Para rodar o projeto localmente, siga os seguintes passos:

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/Vivian-RC/controle-gpio-teclado-matricial-rp2040.git
   ````
2. Entre na pasta do projeto:
````
cd controle-gpio-teclado-matricial-rp2040
````

3. Configuração do Ambiente de Desenvolvimento:

    Utilize o CMake ou o Makefile para compilar o código:

- Para CMake:
````
mkdir build
cd build
cmake ..
make
````

- Para Makefile:
````
make
````

## Simulação no Wokwi:

Após a configuração, você pode usar o simulador Wokwi para testar o circuito. Acesse o simulador através do link do projeto no Wokwi e veja como a interação com o teclado matricial aciona os LEDs, o buzzer e exibe as informações no display LCD1602.

## Delegação de Tarefas

Cada membro do projeto ficou responsável por uma parte específica. Abaixo estão as tarefas delegadas, com o nome do responsável e o nome sugerido para a branch.

| **Membro**           | **Tarefa**                                  | **Branch Sugerida**            |
|----------------------|---------------------------------------------|--------------------------------|
| **Matheus Mato**      | LEDs e Buzzer              | `leds-buzzer` |
| **Vivian Rodrigues**  | Componentes                    | `componentes`      |
| **Daniel Silva**      | Display                    | `display-lcd1602`     |
| **Joelson Santana**    | Display             | `display-lcd1602`|
| **Mychael Matos**     | Main (Arquivo principal)               | `main` |conversor-potencia`   |
| **Caio Bruno**        | Testes e depuração                     | `testes`       |conversor-tempo`      |conversor-dados`      |
| **Adimael Santos**      | Teclado Matricial            | `teclado-matricial`   |
| **Tarefa Livre**      | Construção do README.md              | `main`          |  |

## Prazos e Datas Importantes

- Data de início do projeto: 14/01/2025

- Data para finalizar e subir as tarefas: 17/01/2025 (como combinado durante a reunião)

- Data para revisão e merge das branches: 18/01/2025

- Data final do projeto: 19/01/2025




