Route115_West_LighthouseHome_MapScripts::
	.byte 0

Route115_West_LighthouseHome_EventScript_LighthouseKeeper::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SHED_SHELL, Route115_West_LighthouseHome_EventScript_GiveShedShell
	msgbox Route115_West_LighthouseHome_Text_LighthouseKeeper, MSGBOX_NPC
	release
	end

Route115_West_LighthouseHome_EventScript_GiveShedShell::
	msgbox Route115_West_LighthouseHome_Text_GiveShedShell, MSGBOX_NPC
	giveitem ITEM_SHED_SHELL
	setflag FLAG_RECEIVED_SHED_SHELL
	release
	end

Route115_West_LighthouseHome_Text_GiveShedShell:
	.string "Another trainer, isn't it? But you are\n"
	.string "different.\p"
	.string "Your pokemon follows you rather than\n"
	.string "wait for you to let it out.\p"
	.string "It trusts you, and that deserves some\n"
	.string "recognition the other trainers in the\p"
	.string "peninsula won't get yet.$"

Route115_West_LighthouseHome_Text_LighthouseKeeper:
	.string "Constant visits from trainers can be\n"
	.string "tiring.\p"
	.string "Especially ones who've earned a few\n"
	.string "medals. They get cocky.\p"
	.string "Now go make something out of yourself.$"
