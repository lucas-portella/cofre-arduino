<?php
session_start();

if (!isset($_SESSION['logado']) || $_SESSION['logado'] !== true) {
    header('Location: login.php'); 
    exit;
}
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="assets/styles/style.css">
	<title>Gerenciador Cofre</title>
</head>
<body>
	<div class="index-container">
		<h1>Administração Cofre</h1>
		<h2>Selecione uma das opções abaixo:</h2>
		<nav>
			<a href="listagem-acessos.php">Acessos</a>
			<a href="formulario-cadastro.php">Cadastro de usuários</a>
		</nav>
		<p>Bem-vindo, <?= htmlspecialchars($_SESSION['username']); ?>!</p>
		<a href="logout.php">Sair</a>
	</div>
</body>
</html>
