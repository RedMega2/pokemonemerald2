.set LOCALID_OLD_AMBER, 1

VictoryRoad_Summit_MapScripts::
	.byte 0

VictoryRoad_Summit_EventScript_OldAmber::
	lock
	faceplayer
	msgbox VictoryRoad_Summit_Text_TakeOldAmber, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VictoryRoad_Summit_EventScript_LeaveOldAmber
	giveitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	delay 30
	end

VictoryRoad_Summit_EventScript_LeaveOldAmber::
	msgbox VictoryRoad_Summit_Text_LeftOldAmberAlone, MSGBOX_DEFAULT
	release
	end

VictoryRoad_Summit_Text_TakeOldAmber:
	.string "Take the OLD AMBER?$"

VictoryRoad_Summit_Text_LeftOldAmberAlone:
	.string "{PLAYER} left the OLD AMBER alone.$"
