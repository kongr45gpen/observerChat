observerChat
============

BZFlag plugin that limits observers' participation on global chat.

Usage
-----
The observerChat plugin is easy to use. It takes one parameter, an integer representing the mode it should work on:

    -loadplugin observerChat,1

Possible values:
* `0`: Deactivates the plugin
* `1`: Observers aren't allowed to talk on global chat while a game is in progress **(default)**
* `2`: Observers aren't allowed to talk on global chat at any time

Players who have the `OBSERVERCHAT` permission or admins are allowed to override the plugin and talk wherever they want.

Even more usage
---------------
If you wish to change the mode while in-game, you can set the `_observerChat` variable. It takes the following case-insensitive values:
* `off`: Deactivates the plugin
* `game`: Observers aren't allowed to talk on global chat while a game is in progress **(default)**
* `alwaysOn`: Observers aren't allowed to talk on global chat at any time

Installation by compilation on Linux
------------------------------------

1. Run `git clone https://github.com/kongr45gpen/observerChat.git` on your plugins directory
2. Run `./addToBuild.sh observerChat`
3. On the base bzflag source folder, run:

        make
        sudo make install

4. Add `-loadplugin observerChat` to your server configuration file.

