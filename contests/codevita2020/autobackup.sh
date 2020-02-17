DIR=~/prog
OUT=/media/sf_Z_DRIVE/backups
SLEEP=60

bail_out(){
	echo "$@" > /dev/stderr
	exit 1
}

[ -d $OUT ] || mkdir $OUT || bail_out "Must be root"

while true; do
	outnow="$OUT/$(date +%H_%M_%S)"
	cp -r "$DIR" $outnow
	sleep $SLEEP
done
