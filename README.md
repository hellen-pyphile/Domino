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

