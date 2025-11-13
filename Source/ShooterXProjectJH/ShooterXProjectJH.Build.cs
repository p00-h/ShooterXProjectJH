// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterXProjectJH : ModuleRules
{
	public ShooterXProjectJH(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			// Initial Dependencies.
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			
			// Json Modules
			"Json", "JsonUtilities",
			
			// Input
			"EnhancedInput",
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		PublicIncludePaths.AddRange(new string[] { "ShooterXProjectJH" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
