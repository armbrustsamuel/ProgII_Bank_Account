# Registro de Contas

## Pré-requisitos para funcionamento:
1. Abrir arquivo de contas
2. Abrir arquivo de transações

## Cadastrando conta:
Entre os valores para `Número`, `Cliente` e `Saldo Inicial` da conta a ser criada. Em seguida pressione o botão `Cadastrar`.

Nesse momento, o arquivo de `contas.bin` será atualizado.

## Lendo as contas:
Ao clicar no botão `Ler Contas`, cada uma das contas cadastradas será apresentada em uma linha do editor de texto `Transações da Conta Pesquisada` devido a limitação de espaço na tela.

As contas aparecerão no seguinte formato:

Conta :: Cliente :: Saldo

e.g. 12345 :: Samuel :: 106096

## Pesquisando transações:
Preencha o campo `Número da Conta Pesquisada` e pressione o botão `Pesquisar Transações`. A partir desse momento, todas as transações cadastradas no arquivo `movimentacao.txt` será apresentado na tela para o usuário.

## Atualizando o Saldo:
Adicione novas operações no arquivo `movimentacao.txt` e pressiona o botão `Pesquisar Transações`. Dessa forma o programa atualizará todas as contas cadastradas.

*Obs*:*Não cadastre transações para contas não existentes*
