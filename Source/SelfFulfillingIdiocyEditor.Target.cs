// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SelfFulfillingIdiocyEditorTarget : TargetRules
{
	public SelfFulfillingIdiocyEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("SelfFulfillingIdiocy");
	}
}
