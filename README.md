# 🀄 Dominó — Projeto LP2026

Repositório dedicado ao desenvolvimento de um jogo de dominó completo em C para terminal, suportando partidas entre dois jogadores humanos ou contra o computador (IA), estruturado sob a arquitetura **MVC (Model-View-Controller)**.

---

## 📌 Visão Geral

- 👥 **Modos de Jogo:** 1 Jogador (vs. IA heurística) ou 2 Jogadores locais
- 💾 **Persistência:** Sistema de save/load de partidas em arquivo binário (`TESTEX.txt`)
- 🏛️ **Arquitetura:** Separação estrita em MVC (Model-View-Controller)
- 👥 **Autores:** Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

---

## 🛠️ Tecnologias e Ferramentas

- **C (Padrão C99/C11)**
- **GCC / Clang** (Compilação)
- **Git & GitHub** (Versionamento e controle de versões)

---

## 📁 Estrutura do Repositório

```text
├── Dom_HJRV_PROJETO.c          # main(): Ponto de entrada e semente aleatória
├── Dom_HJRV_Controller.c/.h    # Controller: Fluxo de jogo, menus, turnos e IA
├── Dom_HJRV_Model.c/.h         # Model: Regras, peças, mesa, jogadas e save/load
├── Dom_HJRV_View.c/.h          # View: Interface de terminal (printf/scanf)
├── TESTEX.txt                  # Arquivo binário de persistência de partida
└── README.md                   # Documentação do projeto
```

## 🚀 Como Compilar e Executar
Certifique-se de ter um compilador C instalado no sistema (ex.: gcc).

Clone o repositório:

```Bash
git clone [https://github.com/hellen-pyphile/domino-lp2026.git](https://github.com/hellen-pyphile/domino-lp2026.git)
cd domino-lp2026
```

Compile os módulos do projeto:
```Bash
gcc Dom_HJRV_PROJETO.c Dom_HJRV_Controller.c Dom_HJRV_Model.c Dom_HJRV_View.c -o domino
```
Execute o jogo:
- No Linux / macOS:
```Bash
./domino
```

- No Windows:
```Bash
domino.exe
```

## 🎮 Funcionalidades e Menus
Menu Principal
1. Nova partida: Embaralha (Fisher–Yates) e distribui 7 peças para cada jogador, definindo o modo (1P vs CPU ou 2P).

2. Continuar partida: Carrega a partida salva em TESTEX.txt.

3. Mostrar peças não embaralhadas: Exibe as 28 combinações na ordem de criação.

4. Mostrar peças (embaralhadas): Exibe as peças logo após a rotina de embaralhamento.

5. Regras: Resumo das instruções e regras vigentes.

6. Admin: Modo de depuração para inspeção de estados de peças e visualização bruta da mesa.

0. Sair: Finaliza a aplicação.

Menu Durante a Partida
1. Jogar: Seleção da peça por índice e definição da ponta da mesa (E / D).

2. Comprar: Compra de peças do monte restante.

3. Salvar: Exportação do estado completo para TESTEX.txt.

0. Sair: Encerra a rodada atual.

## 🧠 Heurística da IA
Nas partidas para 1 jogador, a decisão da CPU é calculada automaticamente:

Filtra as peças em mãos (J2) compatíveis com as extremidades abertas (mesaEsq ou mesaDir).

Prioriza a peça com a maior soma de pontos (esq + dir), mitigando o risco de pontuação alta retida na mão caso ocorra trancamento.

Efetua compras dinâmicas no monte se não houver encaixes viáveis; passa o turno caso o monte se esgote.
