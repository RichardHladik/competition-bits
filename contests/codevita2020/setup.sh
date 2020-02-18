NOTEBOOK=icpc-notebook-tooling-updates
BITS=competition-bits-master

setxkbmap cz -option caps:swapescape
mkdir -p prog
[ ! -d $BITS ] && rm -f master.zip && wget https://github.com/RichardHladik/competition-bits/archive/master.zip && unzip master.zip
[ ! -d $NOTEBOOK ] && rm -f tooling-updates.zip && wget https://github.com/trinerdi/icpc-notebook/archive/tooling-updates.zip && unzip tooling-updates.zip
rm -f master.zip tooling-updates.zip

cp $NOTEBOOK/src/trinerdi/{sc.sh,template.cpp} prog
cp $NOTEBOOK/src/trinerdi/vimrc ~/.vimrc
gsettings set org.gnome.desktop.wm.keybindings switch-windows "['<Alt>Tab']"
gsettings set org.gnome.desktop.wm.keybindings switch-windows-backward "['<Shift><Alt>Tab']"
gsettings set org.gnome.desktop.wm.keybindings switch-applications "['<Super>Tab']"
gsettings set org.gnome.desktop.wm.keybindings switch-applications-backward "['<Shift><Super>Tab']"

sudo apt install tmux
sudo apt install vim-gtk3
sudo apt install valgrind

echo OK, launch autobackup now
