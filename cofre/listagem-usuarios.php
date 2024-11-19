<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="assets/styles/style.css">
	<title>Gerenciador Cofre</title>
</head>
<body>
	<h1>Listagem de Usuários</h1>
	
	<?php

			function imprime_cabecalho () {
				echo 
			"<table>
				<tr>
					<th>Usuário</th>
					<th>Senha</th>
				</tr>";
			}

			$file_path = "users/users.csv";
		
			if (!file_exists($file_path)) {
				echo "<h2>Sem registro de usuários.</h2>";
				exit;	
			}

			$file_content = file($file_path);
			if ($file_content) {
				imprime_cabecalho();
				foreach ($file_content as $register) {
					echo "<tr>";
					$itens = explode (",", $register);
					foreach ($itens as $item) 
						echo "<td>".$item."</td>";
					echo "</tr>";
				}
				echo "</table>";	
			}
			
			
	?>
	<nav>
		<a href="users/users.csv" download>Download do arquivo em CSV</a>
		<a href="formulario-cadastro.php">Voltar para o formulário</a>
		<a href="index.php">Voltar para a página principal</a>	
	</nav> 
</body>
</html>
