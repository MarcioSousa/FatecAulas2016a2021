<?php
	$options = array(
    	'uri' => 'http://www.arkau.com.br/webservice/cadastro.php',
    	'location' => 'http://www.arkau.com.br/webservice/cadastro.php'
	);
	
	$server = new SoapServer(null, $options);
	
	require_once('../conexao.php');
	
	class MinhaInterfaceSoap
	{
		
		public function registro($nome, $email, $senha, $cidade)
    	{	
			$sql = "select usuario.usuNome
					from usuario
					where usuario.usuMail = '$email' ";
			$res_usuario = mysql_query( $sql );
			
			$senhacripto = md5($email . $senha);
			
			if( mysql_num_rows( $res_usuario ) == 0 )
			{
				$sql = "insert into usuario(usuMail, usuSenha, usuNome, usuChave, usuStatus, usuTipo, usuCidade)
						values( '$email', '$senha', '$nome', '$senhacripto', 'X', 'J', '$cidade' ) ";
				$res_cadastro = mysql_query( $sql );
				
				$link = "http://www.arkau.com.br/quiz/confirma.php?mail=$email&key=$senhacripto";
				
				require_once('class.phpmailer.php');

				$mail = new PHPMailer();

				$mail->IsSMTP();                            // envia usando SMTP
				$mail->Port     = 587;
				$mail->Host     = "smtp.arkau.com.br"; 		// servidor SMTP
				$mail->SMTPAuth = true;     				// habilita autenticação no SMTP
				$mail->Username = "sistema@arkau.com.br";  	// Usuário SMTP
				$mail->Password = "ArKau@21";				// Senha SMTP

				$mail->From     = "sistema@arkau.com.br";
				$mail->FromName = "QUIZ - Sistema de Controle - Novo Cadastro";
				
				
				$mail->AddAddress( $email, $nome); // e-mail e nome do destinatario
				
				// $mail->AddAttachment( './comprovante/' . $nom1 );
				
				$mail->WordWrap = 70;                              // quebra de linha a cada 50 caracteres

				$mail->IsHTML(true);                               // envia o conteudo em HTML
				
				$mail->Subject  =  'Novo Cadastro - QUIZ';
				$linha = '<p align="center" style="font-weight: bold; font-size: 24px">Novo Cadastro - QUIZ</p>';
				$linha = $linha . '<p align="center">&nbsp;</p>';
				$linha = $linha . '<p align="center">Para confirmar seu cadastro clique no link abaixo ou copie o link e abra em seu navegadro preferido.</p>';
				$linha = $linha . '<p>&nbsp;</p>';
				$linha = $linha . '<p>&nbsp;</p>';
				$linha = $linha . '<p align="center"><a href="$link">' . $link . '</a></p>';
				$linha = $linha . '<p>&nbsp;</p>';
				$linha = $linha . '<p>&nbsp;</p>';
				$linha = $linha . '<p align="center">&nbsp;</p>';
				$linha = $linha . '<p>Cadastro feito em ' . date('d/m/Y') . ' as ' . date('H:i') . '</p>';

				$mail->Body     =  $linha;
				$mail->AltBody  =  "Cadastro do Jogo QUIZ";
				
				$obj = array();
				
				if( ! $mail -> Send() )
				{
					$obj[] = 'ERRO';
					$obj[] = '0';
				}
				else
				{
					$obj[] = 'OK';
					$obj[] = $senhacripto;
				}
			}
			else
			{
				$obj = array();
				
				$obj[] = 'ERRO';
				$obj[] = '0';
			}
			
			return $obj;
    	}
	}

	$server->setObject(new MinhaInterfaceSoap());
 
	$server->handle();
?>