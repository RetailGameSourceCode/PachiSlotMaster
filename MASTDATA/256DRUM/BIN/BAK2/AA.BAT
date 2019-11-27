REM copy bkloff00.tim kmr64_s.tim
REM copy bksoff00.tim kmr50_s.tim
REM copy bklon00.tim kmr64_sn.tim
REM copy bkson00.tim kmr50_sn.tim
call timed kmr50_s.tim 672 0 0 500
call timed kmr50_sn.tim 736 0 0 501
call timed kmr64_s.tim 640 0 0 502
call timed kmr64_sn.tim 704 0 0 503
copy kmr64_s.tim ..\..\256base\bin\all
copy kmr50_s.tim ..\..\256base\bin\all
copy kmr64_sn.tim ..\..\256base\bin\all
copy kmr50_sn.tim ..\..\256base\bin\all
