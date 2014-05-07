#!bash
if [ -z "$2" ]; then
	template="FindContours"
else
	template="$2"
fi
wd=`dirname "$0"`
if [ ! -f "$wd/$1"Plugin.h ]; then
	cp "$wd/"$template"Sidebar.h" "$wd/$1"Sidebar.h
	cp "$wd/"$template"Sidebar.cpp" "$wd/$1"Sidebar.cpp
	cp "$wd/"$template"Plugin.h" "$wd/$1"Plugin.h
	cp "$wd/"$template"Plugin.cpp" "$wd/$1"Plugin.cpp
	for i in "$wd/$1"Sidebar.* "$wd/$1"Plugin.*; do
		sed -e "s/$template/$1/g" -i "$i"
	done
fi
echo "#include \"$1"Plugin.h"\"" >> "$wd/IncludePlugins.h"

php "$wd/addNewPlugin.php" $1