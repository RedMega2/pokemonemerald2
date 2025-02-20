Route102_To_Route101_IsolatedHouse_MapScripts::
	.byte 0

Route102_To_Route101_IsolatedHouse_EventScript_IsolatedMan::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_DAMP_ROCK, Route102_To_Route101_IsolatedHouse_EventScript_FewVisitors
	msgbox Route102_To_Route101_IsolatedHouse_Text_IsolatedMan, MSGBOX_NPC
	release
	end

Route102_To_Route101_IsolatedHouse_EventScript_FewVisitors::
	msgbox Route102_To_Route101_IsolatedHouse_Text_FewVisitors, MSGBOX_NPC
	giveitem ITEM_DAMP_ROCK
	setflag FLAG_RECEIVED_DAMP_ROCK
	release
	end

Route102_To_Route101_IsolatedHouse_Text_FewVisitors:
	.string "Woah! I don't get many visitors around\n"
	.string "here.\p"
	.string "You must be a trainer with that Pokémon\n"
	.string "following you.\p"
	.string "Then you can make use of this little\n"
	.string "souvenir.\p"
	.string "Here, as way of thanks for humoring me.$"

Route102_To_Route101_IsolatedHouse_Text_IsolatedMan:
	.string "Don't get me wrong. I choose to live\n"
	.string "here alone, but I do enjoy some\p"
	.string "conversation from time to time.$"
