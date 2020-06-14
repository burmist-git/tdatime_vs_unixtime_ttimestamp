#!/bin/bash

########################################################################
#                                                                      #
# Copyright(C) 2019 - LBS - (Single person developer.)                 #
# Tue Apr 16 10:58:48 JST 2019                                         #
# Autor: Leonid Burmistrov                                             #
#                                                                      #
# File description:                                                    #
#                                                                      #
# Input paramete:                                                      #
#                                                                      #
# This software is provided "as is" without any warranty.              #
#                                                                      #
########################################################################

LC_TIME=en_US.UTF-8

function tDatime_vs_unixTime_tTimeStamp_bash {
    rm -f tDatime_vs_unixTime_tTimeStamp.root
    watch -n 1 -c ./tDatime_vs_unixTime_tTimeStamp 0
    #timeout 10 watch -n 1 -c ./tDatime_vs_unixTime_tTimeStamp 0
    #timeout 2 sleep 10
} 

function printHelp {
    echo " --> ERROR in input arguments "
    echo " [0] -d  : default"
    echo " [0] -h  : print help"
}

if [ $# -eq 0 ] 
then    
    printHelp
else
    if [ "$1" = "-d" ]; then
	tDatime_vs_unixTime_tTimeStamp_bash
    elif [ "$1" = "-h" ]; then
        printHelp
    else
        printHelp
    fi
fi

#espeak "I have done"
