<?php
session_start();

if (!isset($_SESSION['logado']) || $_SESSION['logado'] !== true) {
    header('Location: login.php');
    exit;
}
?>

<!DOCTYPE HTML>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="assets/styles/style.css">
	<title>Cadastro de Usuários</title>
</head>

<body>
	
	<form action="registra-usuario.php" method="POST">
		<p class="titulo-cadastro">Cadastro de Usuário</p>
		<div class="input-item">
			<label for="usuario">Usuário</label>
			<input name="usuario" type="text" placeholder="Ex.: 0000" required>
		</div>
		<div class="input-item">
			<label for="senha">Senha</label>
			<input name="senha" type="password" placeholder="Ex.: 1234" required>
		</div>
			<input class="submit-buttom" type="submit" value="Enviar">
			<a href="listagem-usuarios.php" class="form-link">Listar usuários cadastrados</a>
			<a href="index.php" class="form-link">Voltar para página principal</a>
	</form>

</body>
</html>
