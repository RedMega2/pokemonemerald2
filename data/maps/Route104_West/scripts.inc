Route104_West_MapScripts::
	.byte 0

Route104_West_EventScript_Sign::
	msgbox Route104_West_Text_Sign, MSGBOX_SIGN
	end

Route104_West_EventScript_Artist::
	msgbox Route104_West_Text_Artist, MSGBOX_NPC
	end

Route104_West_EventScript_Boy::
	msgbox Route104_West_Text_Boy, MSGBOX_NPC
	end

Route104_West_EventScript_Fisherman::
	msgbox Route104_West_Text_Fisherman, MSGBOX_NPC
	end

Route104_West_EventScript_Beo::
	@ TRAINER_DARIAN is a placeholder
	trainerbattle_single TRAINER_DARIAN, Route104_West_Text_BeoIntro, Route104_West_Text_BeoDefeat
	msgbox Route104_West_Text_BeoPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_West_EventScript_Bard::
	@ TRAINER_DARIAN is a placeholder
	trainerbattle_single TRAINER_DARIAN, Route104_West_Text_BardIntro, Route104_West_Text_BardDefeat
	msgbox Route104_West_Text_BardPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_West_Text_Sign:
	.string "Remember to pay attention to your\n"
	.string "surroundings.\p"
	.string "Secret passages are often hidden, but\n"
	.string "there's always a clue.\p"
	.string "Like missing shadows behind a tree or\n"
	.string "misplaced rubble on the floor.$"

Route104_West_Text_Artist:
	.string "What an inspiring view, isn't it?$"

Route104_West_Text_Boy:
	.string "I wonder what lies beyond the sea...$"

Route104_West_Text_Fisherman:
	.string "You can fish some rare pokemon on this\n"
	.string "dock!\p"
	.string "But I don't have all the different rods\n"
	.string "to test...$"

Route104_West_Text_BeoIntro:
	.string "Hey! This spot is ours!$"

Route104_West_Text_BeoDefeat:
	.string "Ok, ok! We can share the view.$"

Route104_West_Text_BeoPostBattle:
	.string "I won't lie, this is a beautiful place for a\n"
	.string "battle.$"

Route104_West_Text_BardIntro:
	.string "A wild artist appears from the woods!$"

Route104_West_Text_BardDefeat:
	.string "The wild artist fainted.$"

Route104_West_Text_BardPostBattle:
	.string "I was hoping a surprise battle would\n"
	.string "inspire my next piece.\p"
	.string "Didn't quite work out though.$"
