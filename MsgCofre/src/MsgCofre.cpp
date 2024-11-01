#include <MsgCofre.h>

void imprimeUsuarioSenha (char* user, char *senha) {
  int i = 0;

  lcd.setCursor(0,0);
  lcd.print("Usuario:");
  while (user[i] != '\0') {
    lcd.print(user[i]);
    i++;
  }
  i = 0;
  lcd.setCursor(0, 1);
  lcd.print("Senha:");
  while (senha[i] != '\0') {
    lcd.print('*');
    i++;
  }
}

void msgAcessoCofreSucesso () {
	lcd.setCursor(5,0);
	lcd.print("Acesso");
	lcd.setCursor(3,1);
	lcd.print("Permitido!");
}

void msgAcessoCofreErro () {
	lcd.setCursor(5,0);
	lcd.print("Acesso");
	lcd.setCursor(4,1);
	lcd.print("Negado!!");
}

/* mensagens de cadastro de usuario */

void msgCadastroSucesso () {
	lcd.setCursor(5,0);
	lcd.print("Usuario");
	lcd.setCursor(4,1);
	lcd.print("cadastrado!");
}

void msgCadastroErro () {
	lcd.setCursor(5,0);
	lcd.print("Falha ao");
	lcd.setCursor(4,1);
	lcd.print("cadastrar!");
}

/* mensagens de remoção de usuario */

void msgRemocaoSucesso () {
	lcd.setCursor(5,0);
	lcd.print("Usuario");
	lcd.setCursor(4,1);
	lcd.print("removido!");
}

void msgRemocaoErro () {
	lcd.setCursor(5,0);
	lcd.print("Falha ao");
	lcd.setCursor(4,1);
	lcd.print("remover usuario!");
}
