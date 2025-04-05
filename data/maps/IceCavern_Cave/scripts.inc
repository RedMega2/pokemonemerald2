IceCavern_Cave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IceCavern_Cave_OnResume
	map_script MAP_SCRIPT_ON_LOAD, IceCavern_Cave_OnLoad
	.byte 0

IceCavern_Cave_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IceCavern_Cave_EventScript_TryRemoveSuicune
	end

IceCavern_Cave_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

IceCavern_Cave_OnLoad:
	call_if_set FLAG_CAUGHT_SUICUNE, IceCavern_Cave_EventScript_HideSuicune
	call_if_unset FLAG_CAUGHT_SUICUNE, IceCavern_Cave_EventScript_TryShowSuicune
	end

IceCavern_Cave_EventScript_HideSuicune::
	setflag FLAG_HIDE_SUICUNE
	return

IceCavern_Cave_EventScript_TryShowSuicune::
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SUICUNE
	return

IceCavern_Cave_EventScript_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 20
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IceCavern_Cave_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IceCavern_Cave_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IceCavern_Cave_EventScript_RanFromSuicune
	setflag FLAG_DEFEATED_SUICUNE
	release
	end

IceCavern_Cave_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	goto Common_EventScript_RemoveStaticPokemon
	end

IceCavern_Cave_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end
