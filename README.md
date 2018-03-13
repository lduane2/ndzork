# ndzork

README.md for ND Zork
---------------------

Zork is an interactive, text-based adventure game written between 1977
and 1979 using the MDL programming language on a DEC PDP-10
computer. It is known for its spontaneous and immersive storytelling
that presents a challenging yet elegant experience for players. Zork
is a great example of making a virtue out of necessity. Great graphics
and video game controllers were not available yet, and the text-based
game of Zork allowed for users' imaginations to take words to new
heights. Zork allowed players to imaginary worlds including caves,
trees, buildings, etc. Today the genre of games that Zork falls into
is an ex-genre, but its legacy lives on. No other game has had as much
emphasis on plain text and prose. Some compare the development of Zork
to that of another classic computer game, Spacewar! The difference
lies in the vision their authors had for the future of computer
games. Spacewar! paved the way for graphical "twitch" games, which
Zork was a game for those who preferred prose to pyrotechnics.

ND Zork is our recreation of the essence of Zork in a modern C++
environment The player is set in a world with well known landmarks,
objects and characters of the Notre Dame campus community like the
Golden Dome, Grotto, Lafortune Student Center, Main Circle,
etc. He/She is tasked with exploring and learning more about the world
and their mission in it. Using the keyboard, a player inputs commands
such as "look" or "go north" that elicit displayed responses from the
program. These interactive responses help progress the player through
game. Some of the goals of our game were to have the computer parse
user input well, provide compelling output and demonstrate AI-like
qualities.

Our implementation of the interactive puzzle game parses user input
into a verb, direct object and indirect object in order to determine
what the player chooses to do with the objects in the game. An example
input would be "look at the statue". This input would result in a
textual response based on whether the command is legitimate or
not. The basic player commands include: look, go(in cardinal
directions), inventory, take(items), and place(items). The player has
an inventory and can interact with items, rooms and even an
NPC. Different items and rooms have their respective restrictions on
interaction. An example of this is how only some objects can be taken
and placed.  There is an overall map with unique rooms in which the
player may move around in. Each room and item may have a description
that provides the player with possible mission clues.

The C++ class hierarchy begins with Object at the root and Actor, Item
and Room all inherit from Object. More specific classes such as
Golden_Dome, candle and luke inherit from Room, Item, and Actor
(respectively). Using polymorphism and the public, protected and
private characteristics of classes, we created an indepth hierarchy of
various objects. This creates allows for a natural cascade when
handling user input.

//Game Spoiler Alert!//
How to Win: The goal is of ND Zork is to save the school. This is
achieved by lighting a candle at the Grotto.  Unfortunately, there are
no candles or matches at the Grotto, so you, as the adventurer, must
find them. If you go to Main Circle and look in the bushes, you should
find your matches. Going North, under the Dome, you should find a
candle. Taking these to the Grotto, you will be able to light the
candle and place it in the cave in order to remove the permacloud and
win the game.
//End Game Spoiler//
