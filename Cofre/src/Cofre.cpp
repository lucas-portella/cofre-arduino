#include <Cofre.h>

void _strcpy (char *original, char *copia) {
	uint i = 0;

	while (original[i] != '\0') {
		copia[i] = original[i];
		i++;
	}
}

uint _strcmp (char *str1, char *str2) {
	uint i = 0;

	while (str1[i] != '\0' && str2[i] != '\0') {
		
		if (str1[i] != str2[i])
			return FALSE;
		i++;
	}

	/* final de string, as ultimas char devem ser '\0'
	 * e coincidir, senao strings de tamanho diferente */
	if (str1[i] != str2[i])
		return FALSE;

	return TRUE;
}

void trocaPosicaoUsuarios (listaUsuarios *lista, uint pos1, uint pos2) {
	cadastro aux;		

	if (pos1 >= lista->numero_usuarios || pos2 >= lista->numero_usuarios)
		return;

	_strcpy(lista->usuarios[pos1].user, aux.user);
	_strcpy(lista->usuarios[pos1].passw, aux.passw);
	aux.adm_access = lista->usuarios[pos1].adm_access;

	_strcpy(lista->usuarios[pos2].user, lista->usuarios[pos1].user);
	_strcpy(lista->usuarios[pos2].passw, lista->usuarios[pos1].passw);
	lista->usuarios[pos1].adm_access = lista->usuarios[pos2].adm_access;

	_strcpy(aux.user, lista->usuarios[pos2].user);
	_strcpy(aux.passw, lista->usuarios[pos1].passw);
	lista->usuarios[pos2].adm_access = aux.adm_access;
}

uint insereUsuario (listaUsuarios *lista, char *user, char *passw, uint adm_access) {
	if (lista->numero_usuarios >= MAX_USERS)	return FALSE;

	uint pos = lista->numero_usuarios;
	_strcpy(user, lista->usuarios[pos].user);
	_strcpy(passw, lista->usuarios[pos].passw);
	lista->usuarios[pos].adm_access = adm_access;
	lista->numero_usuarios++;
	
	return TRUE;
}

void iniciaLista (listaUsuarios *lista, char* adm_user, char* adm_passw) {
	insereUsuario (lista, adm_user, adm_passw, TRUE);
}

uint removeUsuario (listaUsuarios *lista, char *rem_user) {	
	uint i = 0;
	uint removeu = FALSE;

	while (i < lista->numero_usuarios && !removeu) {
		if (_strcmp(rem_user, lista->usuarios[i].user)) {
			trocaPosicaoUsuarios (lista, i, lista->numero_usuarios-1);
			lista->numero_usuarios -= 1;
			removeu = TRUE;
		}
		i++;
	}

	if (removeu)
		return TRUE;
	return FALSE;
}

uint verificaAcesso (listaUsuarios *lista, char *user, char *passw) {
	uint i = 0;

	while (i < lista->numero_usuarios && !_strcmp(user,lista->usuarios[i].user))
		i++;

	if (i == lista->numero_usuarios)
		return FALSE;

	if (_strcmp(passw, lista->usuarios[i].passw))
		return TRUE;
	
	return FALSE;
}

void concatenaLeitura (char* str, char c, uint pos) {
	if (pos < WORD_LENTH) {
		str[pos] = c;
		str[pos+1] = '\0';
	}
}

uint leituraUsuarioSenha (char *user, char *passw) {
	uint i = 0;
	uint usuario_preenchido = FALSE;
	uint senha_preenchida = FALSE;
	
	while (i < WORD_LENTH) {
		imprimeUsuarioSenha(user, passw);
		switch (keypad.getState()) {
			case PRESSED:
				switch (eKey) {
			 		case 'A':
						return OP_ACESSO;
						break;

					case 'B':
						return OP_CADASTRO;
						break;

					case 'C':
						return OP_REMOCAO;
						break;

			 		default:
						if (!usuario_preenchido) {
							concatenaLeitura (user, eKey, i);
							i ++;
							if (i == WORD_LENTH - 1) {
								user[WORD_LENTH - 1] = '\0';
								usuario_preenchido = TRUE;
								i = 0;
							}
						}
						else {
							if (!senha_preenchida) {
								concatenaLeitura (passw, eKey, i);
								i ++;
								if (i == WORD_LENTH - 1) {
									passw[WORD_LENTH - 1] = '\0';
									senha_preenchida = TRUE;
								}
							}
						}
						
						if (usuario_preenchido && senha_preenchida) {
							switch (verificaAcesso(lista, user, passw)) {
								case TRUE:
									msgAcessoCofreSucesso();
									break;
								case FALSE:
									msgAcessoCofreErro();
									break;
							}
							delay(5000);
							return OP_ACESSO;
		

}

uint acessarCofre (listaUsuarios *lista) {
	char user[WORD_LENTH];
	char passw[WORD_LENTH];
	char user[0] = '\0';
	char passw[0] = '\0';
	while (i < WORD_LENTH) {
		imprimeUsuarioSenha(user, passw);
		switch (keypad.getState()) {
			case PRESSED:
				switch (eKey) {
			 		case 'A':
						return OP_ACESSO;
						break;

					case 'B':
						return OP_CADASTRO;
						break;

					case 'C':
						return OP_REMOCAO;
						break;

			 		default:
						if (!usuario_preenchido) {
							concatenaLeitura (user, eKey, i);
							i ++;
							if (i == WORD_LENTH - 1) {
								user[WORD_LENTH - 1] = '\0';
								usuario_preenchido = TRUE;
								i = 0;
							}
						}
						else {
							if (!senha_preenchida) {
								concatenaLeitura (passw, eKey, i);
								i ++;
								if (i == WORD_LENTH - 1) {
									passw[WORD_LENTH - 1] = '\0';
									senha_preenchida = TRUE;
								}
							}
						}
						
						if (usuario_preenchido && senha_preenchida) {
							switch (verificaAcesso(lista, user, passw)) {
								case TRUE:
									msgAcessoCofreSucesso();
									break;
								case FALSE:
									msgAcessoCofreErro();
									break;
							}
							delay(5000);
							return OP_ACESSO;
						}
						else 
							imprimeUsuarioSenha(user,passw);
		  		}
		}
  	}
  
}

uint usuarioAdmin (listaUsuarios *lista, char *user) {
	uint i = 0;

	while (i < lista->numero_usuarios && !_strcmp(user,lista->usuarios[i].user))
		i++;

	if (i == lista->numero_usuarios)
		return FALSE;

	if (lista->usuarios[i].adm_access)
		return TRUE;
	
	return FALSE;
}


