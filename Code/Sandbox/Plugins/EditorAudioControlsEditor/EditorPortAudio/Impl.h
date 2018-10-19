// Copyright 2001-2018 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <IImpl.h>

#include "Item.h"

#include <CrySystem/File/CryFile.h>

namespace ACE
{
namespace Impl
{
namespace PortAudio
{
class CDataPanel;

class CImpl final : public IImpl
{
public:

	CImpl(CImpl const&) = delete;
	CImpl(CImpl&&) = delete;
	CImpl& operator=(CImpl const&) = delete;
	CImpl& operator=(CImpl&&) = delete;

	CImpl();
	virtual ~CImpl() override;

	// IImpl
	virtual void           Initialize(SImplInfo& implInfo, Platforms const& platforms) override;
	virtual QWidget*       CreateDataPanel() override;
	virtual void           DestroyDataPanel() override;
	virtual void           Reload(SImplInfo& implInfo) override;
	virtual IItem*         GetItem(ControlId const id) const override;
	virtual CryIcon const& GetItemIcon(IItem const* const pIItem) const override;
	virtual QString const& GetItemTypeName(IItem const* const pIItem) const override;
	virtual void           SetProjectPath(char const* const szPath) override {}
	virtual bool           IsTypeCompatible(EAssetType const assetType, IItem const* const pIItem) const override;
	virtual EAssetType     ImplTypeToAssetType(IItem const* const pIItem) const override;
	virtual IConnection*   CreateConnectionToControl(EAssetType const assetType, IItem const* const pIItem) override;
	virtual IConnection*   CreateConnectionFromXMLNode(XmlNodeRef pNode, EAssetType const assetType) override;
	virtual XmlNodeRef     CreateXMLNodeFromConnection(IConnection const* const pIConnection, EAssetType const assetType) override;
	virtual XmlNodeRef     SetDataNode(char const* const szTag) override;
	virtual void           EnableConnection(IConnection const* const pIConnection, bool const isLoading) override;
	virtual void           DisableConnection(IConnection const* const pIConnection, bool const isLoading) override;
	virtual void           DestructConnection(IConnection const* const pIConnection) override;
	virtual void           OnAboutToReload() override;
	virtual void           OnReloaded() override;
	virtual void           OnSelectConnectedItem(ControlId const id) const override;
	virtual void           OnFileImporterOpened() override;
	virtual void           OnFileImporterClosed() override;
	// ~IImpl

	CItem const& GetRootItem() const { return m_rootItem; }

private:

	void Clear();
	void SetImplInfo(SImplInfo& implInfo);
	void SetLocalizedAssetsPath();

	using ConnectionIds = std::map<ControlId, int>;

	CItem         m_rootItem { "", s_aceInvalidId, EItemType::None, "" };
	ItemCache     m_itemCache;       // cache of the items stored by id for faster access
	ConnectionIds m_connectionsByID;
	CDataPanel*   m_pDataPanel;
	string        m_implName;
	string const  m_assetAndProjectPath;
	string        m_localizedAssetsPath;
};
} // namespace PortAudio
} // namespace Impl
} // namespace ACE
