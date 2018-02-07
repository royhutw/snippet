USE [LAW]
GO
backup log LAW to disk='NUL:'
GO
DBCC SHRINKFILE (N'LAW_Log' , 0, TRUNCATEONLY)
GO

USE [NP]
GO
backup log NP to disk='NUL:'
GO
DBCC SHRINKFILE (N'NP_Log' , 0, TRUNCATEONLY)
GO

USE [NP_cus]
GO
backup log NP_cus to disk='NUL:'
GO
DBCC SHRINKFILE (N'NP_cus_Log' , 0, TRUNCATEONLY)
GO

USE [NT]
GO
backup log NT to disk='NUL:'
GO
DBCC SHRINKFILE (N'NT_Log' , 0, TRUNCATEONLY)
GO

USE [OL]
GO
backup log OL to disk='NUL:'
GO
DBCC SHRINKFILE (N'OL_Log' , 0, TRUNCATEONLY)
GO

USE [PI]
GO
backup log "PI" to disk='NUL:'
GO
DBCC SHRINKFILE (N'PI_Log' , 0, TRUNCATEONLY)
GO

USE [webC]
GO
backup log webC to disk='NUL:'
GO
DBCC SHRINKFILE (N'tsaileeDB_log' , 0, TRUNCATEONLY)
GO

USE [webE]
GO
backup log webE to disk='NUL:'
GO
DBCC SHRINKFILE (N'tsaileeDB_EN_log' , 0, TRUNCATEONLY)
GO

USE [webJ]
GO
backup log webJ to disk='NUL:'
GO
DBCC SHRINKFILE (N'tsaileeDB_JP_log' , 0, TRUNCATEONLY)
GO