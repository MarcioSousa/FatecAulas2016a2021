set DERBY_INSTALL=%USERPROFILE%\Desktop\db\lib
set CLASSPATH=%DERBY_INSTALL%\lib\derbytools.jar;%DERBY_INSTALL%\lib\derbynet.jar;.
java -jar %DERBY_INSTALL%\derbyrun.jar server start -noSecurityManager