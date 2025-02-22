VictoryRoad_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_Summit_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_Summit_OnResume
	.byte 0

VictoryRoad_Summit_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_Summit_EventScript_TryRemoveJirachi
	end

VictoryRoad_Summit_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

VictoryRoad_Summit_OnLoad:
	call_if_set FLAG_CAUGHT_JIRACHI, VictoryRoad_Summit_EventScript_HideJirachi
	call_if_unset FLAG_CAUGHT_JIRACHI, VictoryRoad_Summit_EventScript_TryShowJirachi
	end

VictoryRoad_Summit_EventScript_HideJirachi::
	setflag FLAG_HIDE_JIRACHI
	return

VictoryRoad_Summit_EventScript_TryShowJirachi::
	goto_if_set FLAG_DEFEATED_JIRACHI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_JIRACHI
	return

VictoryRoad_Summit_EventScript_Jirachi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_Summit_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_Summit_EventScript_RanFromJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_Summit_EventScript_RanFromJirachi
	setflag FLAG_DEFEATED_JIRACHI
	release
	end

VictoryRoad_Summit_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	setweather WEATHER_SHADE
	fadenewbgm MUS_NONE
	doweather
	goto Common_EventScript_RemoveStaticPokemon
	end

VictoryRoad_Summit_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

