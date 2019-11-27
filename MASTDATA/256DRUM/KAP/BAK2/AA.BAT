REM copy kploff00.tim kpr64_s.tim
REM copy kpsoff00.tim kpr50_s.tim
REM copy kplon00.tim kpr64_sn.tim
REM copy kpson00.tim kpr50_sn.tim
call timed kpr50_s.tim 672 0 0 500
call timed kpr50_sn.tim 736 0 0 501
call timed kpr64_s.tim 640 0 0 502
call timed kpr64_sn.tim 704 0 0 503
copy kpr64_s.tim ..\..\256base\kap\all
copy kpr50_s.tim ..\..\256base\kap\all
copy kpr64_sn.tim ..\..\256base\kap\all
copy kpr50_sn.tim ..\..\256base\kap\all
