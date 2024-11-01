#ifndef MSGCOFRE_H
#define MSGCOFRE_H

#include <LiquidCrystal_I2C.h>

/* mensagens de acesso ao cofre */
void imprimeUsuarioSenha (char *user, char *senha);
void msgAcessoCofreSucesso();
void msgAcessoErro();

/*mensagens de cadastro de usuario */
void msgCadastroSucesso();
void msgCadastroErro();

/* mensagens de remocao de usuario */
void msgRemocaoSucesso();
void msgRemocaoErro();


#endif
