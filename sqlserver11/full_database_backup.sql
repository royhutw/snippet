use master
GO

BACKUP DATABASE [LAW] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\LAW.bak' WITH NOFORMAT, INIT,  NAME = N'LAW-Full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'LAW' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'LAW' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''LAW'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\LAW.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [NP] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NP.bak' WITH NOFORMAT, INIT,  NAME = N'NP-Full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'NP' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'NP' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''NP'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NP.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [NP_cus] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NP_cus.bak' WITH NOFORMAT, INIT,  NAME = N'NP_cus-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'NP_cus' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'NP_cus' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''NP_cus'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NP_cus.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [NT] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NT.bak' WITH NOFORMAT, INIT,  NAME = N'NT-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'NT' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'NT' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''NT'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\NT.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [OL] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\OL.bak' WITH NOFORMAT, INIT,  NAME = N'OL-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'OL' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'OL' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''OL'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\OL.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [PI] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\PI.bak' WITH NOFORMAT, INIT,  NAME = N'PI-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'PI' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'PI' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''PI'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\PI.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [webC] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webC.bak' WITH NOFORMAT, INIT,  NAME = N'webC-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'webC' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'webC' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''webC'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webC.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [webE] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webE.bak' WITH NOFORMAT, INIT,  NAME = N'webE-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'webE' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'webE' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''webE'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webE.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO

BACKUP DATABASE [webJ] TO  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webJ.bak' WITH NOFORMAT, INIT,  NAME = N'webJ-full database backup', SKIP, NOREWIND, NOUNLOAD,  STATS = 10
GO
declare @backupSetId as int
select @backupSetId = position from msdb..backupset where database_name=N'webJ' and backup_set_id=(select max(backup_set_id) from msdb..backupset where database_name=N'webJ' )
if @backupSetId is null begin raiserror(N'確認失敗。找不到資料庫 ''webJ'' 的備份資訊。', 16, 1) end
RESTORE VERIFYONLY FROM  DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL11.MSSQLSERVER\MSSQL\Backup\webJ.bak' WITH  FILE = @backupSetId,  NOUNLOAD,  NOREWIND
GO
