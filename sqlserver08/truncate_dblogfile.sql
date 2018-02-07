use fd
go
backup log fd with truncate_only
go
dbcc shrinkfile (fd_log,1)
go

use NP20110602
go
backup log NP20110602 with truncate_only
go
dbcc shrinkfile (NP20110602_log,1)
go

use tlc_cus
go
backup log tlc_cus with truncate_only
go
dbcc shrinkfile (tlc_cus_log,1)
go