mkdir ~/week1
cd ~/week1
mkdir rootfolder
date 
sleep 3
cd rootfolder
touch root.txt
date
sleep 3
cd ~/week1
mkdir homefolder
date 
sleep 3
cd homefolder
touch home.txt
date sleep 3
cd ~/week1
ls / -rt > ~/week1/rootfolder/root.txt | ls /  -rt
ls ~ -rt > ~/week1/homefolder/home.txt | ls ~ -rt

