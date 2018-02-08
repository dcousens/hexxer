#!/bin/bash -e

function sha256 () {
	sha256sum --binary | grep -o '[a-z0-9]\+'
}

count=$(($(<./fixtures.json jq "length") - 1))
for i in $(seq 0 "$count"); do
	echo -ne "\\nTest $i"

	expected=$(<fixtures.json jq -rj ".[$i].text")
	if [[ "$expected" == "null" ]]; then
		actual=$(<fixtures.json jq -rj ".[$i].hex" | ../hexxer --decode | sha256)
		expected=$(<fixtures.json jq -rj ".[$i].hash")
	else
		actual=$(<fixtures.json jq -rj ".[$i].hex" | ../hexxer --decode)
	fi

	if [[ "$actual" != "$expected" ]]; then
		echo -n "... Failed, needed $expected, got $actual"
		exit 1
	fi

	echo "... Pass"
done
