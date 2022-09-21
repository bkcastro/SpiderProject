cmake_minimum_required(VERSION 3.17)
project(SpiderProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpiderProject main.cpp Menu.cpp Menu.h Button.cpp Button.h States.cpp States.h Fonts.cpp Fonts.h Rank.cpp Rank.h Images.cpp Images.h Card.cpp Card.h Game.cpp Game.h Deck.cpp Deck.h CardButton.cpp CardButton.h CardButton.cpp Field.cpp Field.h Backside.cpp Backside.h Basket.cpp Basket.h Bounds.cpp Bounds.h Stack.cpp Stack.h StackFrame.cpp StackFrame.h Score.cpp Score.h)

target_link_libraries(SpiderProject sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)