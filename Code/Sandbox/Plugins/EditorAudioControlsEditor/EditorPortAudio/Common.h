// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include "Item.h"

#include <CryIcon.h>
#include <FileDialogs/ExtensionFilter.h>

namespace ACE
{
namespace Impl
{
namespace PortAudio
{
extern uint32 g_triggerConnections;

static CryIcon s_errorIcon;
static CryIcon s_eventIcon;
static CryIcon s_folderIcon;

static QString const s_emptyTypeName("");
static QString const s_eventTypeName("Audio File");
static QString const s_folderTypeName("Folder");

static QStringList const s_supportedFileTypes { "wav" };

static ExtensionFilterVector const s_extensionFilters(
			{
				CExtensionFilter("Wave (Microsoft)", "wav")
			});

//////////////////////////////////////////////////////////////////////////
inline void InitIcons()
{
	s_errorIcon = CryIcon("icons:Dialogs/dialog-error.ico");
	s_eventIcon = CryIcon("icons:audio/impl/portaudio/event.ico");
	s_folderIcon = CryIcon("icons:General/Folder.ico");
}

//////////////////////////////////////////////////////////////////////////
inline CryIcon const& GetTypeIcon(EItemType const type)
{
	switch (type)
	{
	case EItemType::Event:
		return s_eventIcon;
		break;
	case EItemType::Folder:
		return s_folderIcon;
		break;
	default:
		return s_errorIcon;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
inline QString const& TypeToString(EItemType const type)
{
	switch (type)
	{
	case EItemType::Event:
		return s_eventTypeName;
		break;
	case EItemType::Folder:
		return s_folderTypeName;
		break;
	default:
		return s_emptyTypeName;
		break;
	}
}
} // namespace PortAudio
} // namespace Impl
} // namespace ACE
