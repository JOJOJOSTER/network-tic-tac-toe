cmake_minimum_required(VERSION 3.15)

project(tic-tac-toe)

set(NON_NETWORK_TIC_TAC_TOE_INCLUDE_DIR non-network-tic-tac-toe/include)

set(NON_NETWORK_TIC_TAC_TOE_SRC_DIR non-network-tic-tac-toe/src)

add_executable(non-network-tic-tac-toe 
               ${NON_NETWORK_TIC_TAC_TOE_INCLUDE_DIR}/non-network-tic-tac-toe-game.h 
               ${NON_NETWORK_TIC_TAC_TOE_INCLUDE_DIR}/map.h
               ${NON_NETWORK_TIC_TAC_TOE_SRC_DIR}/non-network-tic-tac-toe.cpp
               ${NON_NETWORK_TIC_TAC_TOE_SRC_DIR}/non-network-tic-tac-toe-game.cpp
               ${NON_NETWORK_TIC_TAC_TOE_SRC_DIR}/map.cpp)

