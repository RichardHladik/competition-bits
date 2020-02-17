fail(){
	echo "$@" > /dev/stderr
	exit 1
}

dir="$1"
[ -z "$dir" ] && dir="$(dirname "$0")"

cd "$dir" || fail "Cannot cd"
for i in `find . -not -path '*/\.*' -type f`; do
	echo ==="$i"===
	if grep -qI . "$i"; then
		cat "$i"
	else
		echo Seems like a binary, skipping
	fi
done
