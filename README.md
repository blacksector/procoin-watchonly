<b>ProCoin (PCN)</b> is now on version 1.2. Wallet Version is 0.6.3.0. This current branch contains the newest release.</br>

<b>Installation. Sample ProCoin.conf</b> - to run a public node just change rpcallowip=* to allow any client to connect.

<br /><b>Clone the source:</b> git clone https://github.com/getprocoin/Source procoin<br />

rpcuser=procoinrpc<br />
rpcpassword=yourpassword<br />
rpcallowip=localhost<br />
listen=1<br />
gen=0<br />
server=1<br />
rpcport=22444<br />
port=22445<br />
addnode=188.226.162.248<br />
addnode=107.170.122.156<br />
addnode=128.199.202.69<br />
addnode=107.170.71.82<br />
addnode=107.170.207.41<br />
addnode=91.78.212.92<br />
addnode=86.163.160.75<br />
addnode=95.85.52.246<br />
addnode=95.85.52.246<br />
addnode=188.226.189.61<br />
addnode=99.54.90.39<br />
addnode=87.211.164.253<br />

<b>Compiling on Ubuntu:</b>
<br />
You need this if Boost fails on compile:<br />
sudo apt-get install libboost1.48-all-dev<br />
cd src<br />
make -j2 -f makefile.unix USE_UPNP=-<br />
