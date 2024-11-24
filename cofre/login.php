<?php
session_start();

$mensagem = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $usuarios = [
        'admin' => 'senha123'
    ];

    $username = $_POST['username'] ?? '';
    $password = $_POST['password'] ?? '';

    if (isset($usuarios[$username]) && $usuarios[$username] === $password) {
        $_SESSION['logado'] = true;
        $_SESSION['username'] = $username;
        header('Location: index.php'); 
        exit;
    } else {
        $mensagem = 'Usuário ou senha inválidos!';
    }
}
?>

<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="assets/styles/style.css">
    <title>Login</title>
</head>
<body>
    <form method="POST" action="">
        <h1>Tela de Login</h1>
        <?php if ($mensagem): ?>
            <p style="color: red;"><?= $mensagem ?></p>
        <?php endif; ?>
        <div>
            <label for="username">Usuário:</label>
            <input type="text" id="username" name="username" required>
        </div>
        <div>
            <label for="password">Senha:</label>
            <input type="password" id="password" name="password" required>
        </div>
        <input type="submit" value="Entrar">
    </form>
</body>
</html>
