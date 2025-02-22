Route116_StreamHouse_MapScripts::
	.byte 0

Route116_StreamHouse_EventScript_Kirlia::
	lock
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox Route116_StreamHouse_Text_StayingWithFriend, MSGBOX_NPC
	release
	end

Route116_StreamHouse_EventScript_ThatsNotYours::
	lockall
	playmoncry SPECIES_KIRLIA, CRY_MODE_ENCOUNTER
	call_if_eq VAR_TEMP_0, 0, Route116_StreamHouse_EventScript_MoveKirlia
	applymovement 2, Route116_StreamHouse_Movement_KirliaFaceDown
	msgbox Route116_StreamHouse_Text_ThatsNotYours, MSGBOX_NPC
	release
	end

Route116_StreamHouse_EventScript_MoveKirlia::
	setvar VAR_TEMP_0, 1
	applymovement 2, Route116_StreamHouse_Movement_Kirlia
	waitmovement 2
	return

Route116_StreamHouse_Movement_Kirlia::
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_left
	step_end

Route116_StreamHouse_Movement_KirliaFaceDown::
	face_down
	step_end

Route116_StreamHouse_Text_ThatsNotYours:
	.string "(Do you always barge into people's\n"
	.string "homes and take their belongings?)$"

Route116_StreamHouse_Text_StayingWithFriend::
	.string "(This is the home of my trainer's\n"
	.string "friend)\p"
	.string "(I don't think you should be here\n"
	.string "while they are both absent)$"
