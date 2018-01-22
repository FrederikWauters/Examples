#!/bin/bash
use SSH::RPC::Client;
 
host="10.32.113.249"
user="daq"
command="uname" 
 
my $rpc = SSH::RPC::Client->new($host, $user);
my $result = $rpc->run($command, \%args); # returns a SSH::RPC::Result object
 
if ($result->isSuccess) {
   say $result->getResponse;
}
else {
   die $result->getError;
}
