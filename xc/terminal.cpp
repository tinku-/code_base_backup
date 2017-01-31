alias c='clear'
alias cdcf='cd /home/ridam/code/cf'
alias cdjava='cd /home/ridam/code/java'
alias cdhr='cd /home/ridam/code/hr'
alias cdspoj='cd /home/ridam/code/spoj'
alias cdblocks='cd /home/ridam/code/blocks'
alias cdlearning='cd /home/ridam/code/learning'
alias cdxc='cd /home/ridam/code/xc'
alias cdpe='cd /home/ridam/code/pe'
alias disco='cd /home/ridam/code/disco'
alias cdalgo='cd /home/ridam/code/algorithm'
alias rh='rm ~/.bash_history'
alias b25='xbacklight -set 25'
alias android='cd /home/ridam/android/android-studio/bin'
alias cddsa='cd /home/ridam/code/3-2'
alias cdmonk='cd /home/ridam/code/codemonk'
alias runstudio="./studio.sh"

vnstat	
{internet usage stats}
	 		
nm-tool 
{ipconfig equivalent in linux}	

rm ~/.bash_history //remove command history from teminal 
//but there are two command history one for user and one for root remove
//from both............................
{brightness control}
sudo apt-get install xbacklight 
{
	xbacklight -inc 10
	xbacklight -dec 10
	xbacklight -set 20
}

{volume control}
amixer sset Master 81               //set volume to 81% of max
amixer -q sset Master 3%+ 	      	//increase by 3%
amixer -q sset Master 3%-  			//# decrease by 3%
amixer -q sset Master toggle 		//# mute/unmute

xinput list //lists all the input devices 
xinput -disable 13 //disable device with id=13 (in the list) 
xinput enable 13 //enable device with id=-13 (in the list)
{touch pad}
xinput -disable 13
{}
for app in /usr/share/applications/*.desktop; do echo "${app:24:-8}"; done


*/
sudo pm-suspend

rhythmbox-client --help

	