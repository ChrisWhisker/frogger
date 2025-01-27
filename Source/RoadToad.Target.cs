// Copyright © Chris Worcester 2023 All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RoadToadTarget : TargetRules
{
	public RoadToadTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "RoadToad" } );
	}
}
