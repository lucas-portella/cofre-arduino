<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="stylesheet" href="assets/styles/style.css">
	<title>Gerenciador Cofre</title>
</head>
<body>
	<h1>Listagem de Acessos</h1>
	
	<?php

			function imprime_cabecalho () {
				echo 
			"<table>
				<tr>
					<th>Data</th>
					<th>Horário</th>
					<th>Usuário</th>
					<th>Acesso</th>
				</tr>";
			}

			$file_path = "logs/logs.csv";
		
			if (!file_exists($file_path)) {
				echo "<h2>Sem registro de acessos.</h2>";
				exit;	
			}

			$file_content = file($file_path);
			if ($file_content) {
				imprime_cabecalho();
				foreach ($file_content as $register) {
					$itens = explode (",", $register);
					foreach ($itens as $item ) {
						if (strcmp($item, "permitido\n") == 0) 
							echo "<td class=\"permitido\">".$item."</td>";
						else {
							if (strcmp($item, "negado\n") == 0)
								echo "<td class=\"negado\">".$item."</td>";
							else
								echo "<td>".$item."</td>";
						}
					}
					echo "</tr>";
				}
				echo "</table>";	
			}
			
			
	?>
	<nav>
		<a href="logs/logs.csv" download>Download do arquivo em CSV</a>
		<a href="index.php">Voltar para a página principal</a>	
	</nav> 
</body>
</html>
