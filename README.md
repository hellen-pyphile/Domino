# Dominó — Projeto LP2026

Jogo de dominó em C, jogável no terminal, para 2 jogadores humanos ou 1 jogador contra o computador (IA). Desenvolvido em arquitetura **MVC (Model-View-Controller)** como projeto da disciplina de Linguagem de Programação (LP2026).

**Autores:** Hellen Araujo da Silva, João Vitor Carvalho Magalhães Quintella, Rodrigo Corio Ferrer dos Santos, Victoria Spina Tavares

## Sumário

- [Estrutura do projeto](#estrutura-do-projeto)
- [Como compilar e executar](#como-compilar-e-executar)
- [Menus e funcionalidades](#menus-e-funcionalidades)
- [Regras implementadas](#regras-implementadas)
- [IA do computador](#ia-do-computador)
- [Salvar e continuar partida](#salvar-e-continuar-partida)
- [Requisitos atendidos](#requisitos-atendidos)

## Estrutura do projeto

O código segue o padrão MVC, separado em três módulos independentes mais o ponto de entrada:

```
Dom_HJRV_PROJETO.c     → main(): inicializa a semente aleatória e chama o Controller
Dom_HJRV_Controller.c/h → fluxo do jogo: menus, turnos, IA do computador
Dom_HJRV_Model.c/h      → regras e estado do jogo: peças, mesa, jogadas, vitória, save/load
Dom_HJRV_View.c/h       → toda a entrada/saída no terminal (printf/scanf), sem lógica de jogo
```

**Principais tipos de dados (`Dom_HJRV_Model.h`)**

| Tipo | Descrição |
|---|---|
| `Peca` | Uma peça de dominó: `esq`, `dir` e `sts` (status: `Disp`, `J1`, `J2` ou `Mesa`) |
| `Partida` | Estado completo do jogo: as 28 peças, a mesa, turno atual e extremidades (`mesaEsq`/`mesaDir`) |
| `Situacao` | Estrutura auxiliar usada para gravar/carregar uma partida em arquivo binário |

## Como compilar e executar

Requer um compilador C (`gcc` ou equivalente).

```bash
gcc Dom_HJRV_PROJETO.c Dom_HJRV_Controller.c Dom_HJRV_Model.c Dom_HJRV_View.c -o dominó
./dominó        # Linux/Mac
dominó.exe      # Windows
```

## Menus e funcionalidades

Menu principal (`mostrarMenu(1)`):

1. **Nova partida** — cria, embaralha e distribui as 28 peças (7 para cada jogador) e pergunta se será 1 jogador (contra a CPU) ou 2 jogadores
2. **Continuar partida** — carrega o estado salvo em `TESTEX.txt`, se existir
3. **Mostrar peças não embaralhadas** — lista as 28 combinações na ordem de criação
4. **Mostrar peças (embaralhadas)** — lista as peças após o Fisher–Yates shuffle
5. **Regras** — submenu com o resumo das regras do jogo
6. **Admin** — submenu para inspecionar o status de cada peça e visualizar a mesa "crua"
0. **Sair**

Durante a partida (`mostrarMenu(5)`):

1. **Jogar** — informa o índice da peça e o lado (`E`/`D`) desejado
2. **Comprar** — compra uma peça do monte
3. **Salvar** — grava o estado atual da partida em `TESTEX.txt`
0. **Sair** — encerra a partida em andamento

## Regras implementadas

- Cada jogador começa com 7 peças; as demais ficam no monte, disponíveis para compra
- Quem possui a maior carroça (duplo) começa o jogo; na ausência de duplos, vence quem tiver a peça de maior soma
- Os turnos se alternam entre os dois jogadores
- Uma peça só pode ser jogada em um lado da mesa (`E` ou `D`) se um dos seus valores bater com a extremidade correspondente
- Se o jogador não tiver jogada possível, ele deve comprar peças até conseguir jogar ou até o monte esvaziar (podendo comprar por blefe mesmo tendo jogada)
- **Fim de jogo:**
  - Vitória imediata para quem esvaziar a mão primeiro
  - **Jogo trancado** (monte vazio e nenhum dos dois consegue jogar): vence quem tiver menos peças na mão; em caso de empate, vence quem tiver a menor soma de pontos; se ainda assim empatar, o jogo termina empatado

## IA do computador

Quando a partida é "1 jogador", o jogador 2 é controlado pela função `executarTurnoComputador` (Controller), que delega a decisão à heurística `escolherMelhorPeca`:

1. Percorre as peças do computador (`sts == J2`)
2. Filtra as que encaixam em `mesaEsq` ou `mesaDir`
3. Entre as jogáveis, escolhe a de **maior soma de pontos** (`esq + dir`) — jogar as peças "pesadas" primeiro reduz o risco de ficar com pontos altos na mão caso o jogo tranque
4. Se nenhuma peça for jogável, o computador compra do monte e repete o processo; se o monte acabar, passa a vez

## Salvar e continuar partida

`salvaJogo`/`carregaJogo` (Model) gravam/leem, em modo binário, uma `Situacao` completa em `TESTEX.txt`: as 28 peças com seus status atuais, a mesa, o turno, as extremidades e se a partida era contra o computador — permitindo retomar exatamente de onde parou pelo menu **Continuar partida**.

## Requisitos atendidos

| Arquivo | Requisitos |
|---|---|
| `Dom_HJRV_Controller.c` | Req07, Req14, Req17 |
| `Dom_HJRV_Model.c` / `.h` | Req08, Req09, Req10, Req11, Req12, Req15, Req16 |
| `Dom_HJRV_View.c` | Req07, Req09, Req13, Req14, Req17 |
