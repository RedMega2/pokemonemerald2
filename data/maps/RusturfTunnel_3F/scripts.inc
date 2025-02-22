RusturfTunnel_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RusturfTunnel_3F_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, RusturfTunnel_3F_OnResume
	.byte 0

RusturfTunnel_3F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, RusturfTunnel_3F_EventScript_TryRemoveMewtwo
	end

RusturfTunnel_3F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

RusturfTunnel_3F_OnLoad:
	call_if_set FLAG_CAUGHT_MEWTWO, RusturfTunnel_3F_EventScript_HideMewtwo
	call_if_unset FLAG_CAUGHT_MEWTWO, RusturfTunnel_3F_EventScript_TryShowMewtwo
	end

RusturfTunnel_3F_EventScript_OldAmber::
	lock
	faceplayer
	msgbox RusturfTunnel_3F_Text_TakeOldAmber, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RusturfTunnel_3F_EventScript_LeaveOldAmber
	giveitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_OLD_AMBER
	removeobject VAR_LAST_TALKED
	delay 30
	end

RusturfTunnel_3F_EventScript_LeaveOldAmber::
	msgbox RusturfTunnel_3F_Text_LeftOldAmberAlone, MSGBOX_DEFAULT
	release
	end

RusturfTunnel_3F_EventScript_HideMewtwo::
	setflag FLAG_HIDE_MEWTWO
	return

RusturfTunnel_3F_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return

RusturfTunnel_3F_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RusturfTunnel_3F_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, RusturfTunnel_3F_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, RusturfTunnel_3F_EventScript_RanFromMewtwo
	setflag FLAG_DEFEATED_MEWTWO
	release
	end

RusturfTunnel_3F_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

RusturfTunnel_3F_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

RusturfTunnel_3F_EventScript_Noxzus::
	msgbox RusturfTunnel_3F_Text_Noxzus, MSGBOX_NPC
	end

RusturfTunnel_3F_Text_Noxzus:
	.string "Are you the champion?$"

RusturfTunnel_3F_Text_TakeOldAmber:
	.string "Take the OLD AMBER?$"

RusturfTunnel_3F_Text_LeftOldAmberAlone:
	.string "{PLAYER} left the OLD AMBER alone.$"
