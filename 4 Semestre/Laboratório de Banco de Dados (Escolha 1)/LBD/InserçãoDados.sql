USE PEDIDO
GO

INSERT INTO Cliente VALUES(1,'Alexandre Camargo','Rua da Varzea 231','Sorocaba','13210-212','SP')
GO
INSERT INTO Cliente VALUES(2,'Roberta Silva','Rua Sorocaba 789','Itu','12321-111','SP')
GO
INSERT INTO Cliente VALUES(3,'André Silveira','Rua Central 878','Campinas','10101-000','SP')
GO
INSERT INTO Cliente VALUES(4,'Anderson Teixeira','Avenida da Consolação','Piracicaba','14521-010','SP')
GO
INSERT INTO Cliente VALUES(5,'Sandra Tete','Rua Teixeira','Salto','15213-521','SP')
GO


INSERT INTO Vendedor VALUES(1,'Guilherme Arruda',13.20,852.00)
GO
INSERT INTO Vendedor VALUES(2,'Thiago Santiago',13.20,852.10)
GO
INSERT INTO Vendedor VALUES(3,'Amanda Silva',13.20,992.60)
GO
INSERT INTO Vendedor VALUES(4,'Hugo Catarazo',13.20,890.40)
GO
INSERT INTO Vendedor VALUES(5,'José Santiago',13.20,987.30)
GO


INSERT INTO Produto VALUES(1,'Teclado de Desktop',6, 32.00)
GO
INSERT INTO Produto VALUES(2,'Computador HP',7, 890.00)
GO
INSERT INTO Produto VALUES(3,'Pen Drive 120Gb',8, 480.60)
GO
INSERT INTO Produto VALUES(4,'Placa Mãe ABC',6, 190.60)
GO
INSERT INTO Produto VALUES(5,'Mouse',120,19.90)
GO

INSERT INTO Pedido VALUES(1,'12/10/2015',3,4)
GO
INSERT INTO Pedido VALUES(2,'05/08/2015',4,2)
GO
INSERT INTO Pedido VALUES(3,'01/12/2015',1,3)
GO
INSERT INTO Pedido VALUES(4,'22/10/2015',3,4)
GO
INSERT INTO Pedido VALUES(5,'01/02/2015',4,5)
GO

INSERT INTO Item_Pedido VALUES(1,5,6)
GO
INSERT INTO Item_Pedido VALUES(2,1,2)
GO
INSERT INTO Item_Pedido VALUES(3,1,4)
GO
INSERT INTO Item_Pedido VALUES(4,4,7)
GO
INSERT INTO Item_Pedido VALUES(5,3,3)
GO