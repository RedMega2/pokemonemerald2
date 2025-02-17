Route113_Ledge_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113_Ledge_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route113_Ledge_OnLoad
	.byte 0

Route113_Ledge_OnResume:
	setstepcallback STEP_CB_ASH
	end

Route113_Ledge_OnLoad:
	setweather WEATHER_VOLCANIC_ASH
	end
