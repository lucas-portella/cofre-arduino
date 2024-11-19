<!DOCTYPE HTML>

<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="assets/styles/style.css">
	<title>Cadastro de Usuários</title>
</head>
<body>
	<div class="post">
		  <?php
			  function inclui_usuario ($path, $usuario, $senha) {
				  $handle = fopen($path, "a");
				  $rv = false;

				  if ($handle) {
					  fwrite($handle, $usuario.",".$senha."\n");
					  fclose($handle);
					  $rv = true;	
				  }	

				  return $rv;
			  }

			  $path_arquivo = "users/users.csv";
			  $existe_arquivo = false;
			  $novo_usuario = $_POST["usuario"];
			  $nova_senha = $_POST["senha"];
			  $usuario_cadastrado = false;
			  $lista_usuarios = NULL;
			  $cadastro_sucesso = false;
			  

			  if (strcmp($novo_usuario, "") == 0 || strcmp($nova_senha, "") == 0) {
				  echo "<h2>Erro ao cadastrar novo usuário.</h2>";
				  exit;
			  }
			  

			  if (file_exists($path_arquivo)) {
				  $existe_arquivo = true;
				  $lista_usuarios = file($path_arquivo);
			  }
			  
			  if (!$existe_arquivo) 
				  $cadastro_sucesso = inclui_usuario($path_arquivo, $novo_usuario, $nova_senha);
			  

			  if ($lista_usuarios) {
				  foreach ($lista_usuarios as $linha) {
					  $registro = explode (",", $linha);
					  if (strcmp($registro[0], $novo_usuario) == 0) {
						  $usuario_cadastrado = true;
						  break;	
					  }
				  }	
			  }	

			  if (!$usuario_cadastrado) 
				  $cadastro_sucesso = inclui_usuario($path_arquivo, $novo_usuario, $nova_senha);
			  

			  if ($cadastro_sucesso)
				  echo "<h2>Usuário ".$novo_usuario." cadastrado com sucesso</h1>";
			  else {
				  if ($usuario_cadastrado) 
					  echo "<h2>Erro ao cadastrar novo usuário ".$novo_usuario.": Usuário já cadastrado.</h2>";
				  else
					  echo "<h2>Erro ao cadastrar novo usuário.</h2>";
			  }
		  ?>
	</div>
	
	<nav>
		<a href="formulario-cadastro.php">Voltar para o formulário</a>
		<a href="index.php">Voltar para a página principal</a>
	</nav>
</body>
</html>
