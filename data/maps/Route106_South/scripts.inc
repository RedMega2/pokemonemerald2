Route106_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route106_South_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route106_South_OnLoad
	.byte 0

Route106_South_OnTransition::
	goto_if_eq VAR_ROUTE106_STATE, 2, Route106_South_EventScript_ResetVar
	end

Route106_South_OnLoad::
	goto_if_eq VAR_ROUTE106_STATE, 2, Route106_South_EventScript_ResetVar
	end

Route106_South_EventScript_ResortSign::
	msgbox Route106_South_Text_ResortSign, MSGBOX_SIGN
	end

Route106_South_EventScript_Fisherman::
	msgbox Route106_South_Text_FishermanCourage, MSGBOX_NPC
	end

Route106_South_EventScript_ResortIntroduction::
	setvar VAR_ROUTE106_STATE, 1
	lock
	dofieldeffectexclamation 2, 4, 36
	@ setfieldeffectargument 0, 2
	@ setfieldeffectargument 1, 4
	@ setfieldeffectargument 2, 36
	@ playse SE_SELECT
	@ dofieldeffect FLDEFF_EXCLAMATION_MARK_ICON
	applymovement 2, Route106_South_Movement_FishermanLookAtPlayer
	msgbox Route106_South_Text_FishermanScared, MSGBOX_NPC
	applymovement 2, Route106_South_Movement_FishermanLookAtResort
	waitmovement 2
	msgbox Route106_South_Text_FishermanResort, MSGBOX_NPC
	applymovement 2, Route106_South_Movement_FishermanLookAtStairs
	msgbox Route106_South_Text_FishermanStairs, MSGBOX_NPC
	release
	end

Route106_South_EventScript_ResortLeftWindow::
	setvar VAR_ROUTE106_STATE, 2
	applymovement 3, Route106_South_Movement_WindowWalkRight
	end

Route106_South_EventScript_ResortTopWindow::
	setvar VAR_ROUTE106_STATE, 2
	applymovement 4, Route106_South_Movement_WindowWalkLeft
	end

Route106_South_EventScript_ResortRightWindow::
	setvar VAR_ROUTE106_STATE, 2
	applymovement 5, Route106_South_Movement_WindowWalkLeft
	end

Route106_South_EventScript_ResetVar::
	setvar VAR_ROUTE106_STATE, 1
	end

Route106_South_Movement_WindowWalkRight::
	walk_right
	walk_right
	step_end

Route106_South_Movement_WindowWalkLeft::
	walk_left
	walk_left
	step_end

Route106_South_Movement_FishermanLookAtPlayer::
	face_right
	step_end

Route106_South_Movement_FishermanLookAtResort::
	walk_left
	walk_left
	step_end

Route106_South_Movement_FishermanLookAtStairs::
	face_down
	step_end

Route106_South_Text_ResortSign:
	.string "SEASIDE RESORT\n"
	.string "A good night's sleep beside the sea.$"

Route106_South_Text_FishermanScared:
	.string "AH! Sorry, you caught me off guard.$"

Route106_South_Text_FishermanResort:
	.string "That dilapidated building over there\n"
	.string "has me on edge.\p"
	.string "I'm from Slateport, currently visiting\n"
	.string "a fishing buddy.\p"
	.string "I got curious about this desolate\n"
	.string "place.\p"
	.string "But he told me there's only an\n"
	.string "Abandoned Resort here.\p"
	.string	"I haven't seen anyone go inside\n"
	.string "but I swear it.\p"
	.string "Several people have walked past those\n"
	.string "windows!$"

Route106_South_Text_FishermanStairs:
	.string "It doesn't help that the whole area\n"
	.string "has been taken over by Ghost Pokémon$"

Route106_South_Text_FishermanCourage:
	.string "I don't think I can gather the\n"
	.string "courage to go down these stairs.$"
