import os

Import('*')

LIBOGG = env.Glob('deps/libogg-1.3.1/src/*.c')

libogg = env.Library(['ogg'], LIBOGG)

LIBVORBIS = [os.path.join('deps', 'libvorbis-1.3.3', 'lib', x) for x in env.Split("""
    mdct.c smallft.c block.c envelope.c window.c lsp.c 
    lpc.c analysis.c synthesis.c psy.c info.c
    floor1.c floor0.c\
    res0.c mapping0.c registry.c codebook.c sharedbook.c\
    lookup.c bitrate.c vorbisfile.c""")]

libvorbis = env.Library(['vorbis'], LIBVORBIS)

env.VariantDir('freealut', '$EMHOME/tests/freealut', duplicate=0)

LIBFREEALUT = [os.path.join('freealut', 'src', x) for x in Split("""
    alutBufferData.c
    alutCodec.c
    alutError.c
    alutInit.c
    alutInputStream.c
    alutLoader.c
    alutOutputStream.c
    alutUtil.c
    alutVersion.c
    alutWaveform.c
""")]
libfreealut = env.Library(['freealut'], LIBFREEALUT)

env.VariantDir('freetype', '$EMHOME/tests/freetype', duplicate=0)

"""
    autofit/autofit.c
    autofit/aflatin2.c

    # mac-only
    base/ftmac.c

    # has main()
    tools/apinames.c
    tools/ftrandom/ftrandom.c
    tools/test_afm.c
    tools/test_bbox.c
    tools/test_trig.c
    gxvalid/gxvfgen.c

    base/ftbase.c
    bdf/bdf.c
    cache/ftcache.c
    cff/cff.c
    cid/type1cid.c
    gxvalid/gxvmod.c
    otvalid/otvmod.c
    pcf/pcf.c
    pfr/pfr.c
    psaux/psaux.c
    pshinter/pshinter.c
    psnames/psnames.c
    raster/raster.c
    sfnt/sfnt.c
    sfnt/ttsbit0.c
    smooth/smooth.c
    truetype/truetype.c
    type1/type1.c
    type42/type42.c
"""

LIBFREETYPE = [os.path.join('freetype', 'src', x) for x in Split("""
    autofit/afangles.c
    autofit/afcjk.c
    autofit/afdummy.c
    autofit/afglobal.c
    autofit/afhints.c
    autofit/afindic.c
    autofit/aflatin.c
    autofit/afloader.c
    autofit/afmodule.c
    autofit/afpic.c
    autofit/afwarp.c
    base/basepic.c
    base/ftadvanc.c
    base/ftapi.c
    base/ftbbox.c
    base/ftbdf.c
    base/ftbitmap.c
    base/ftcalc.c
    base/ftcid.c
    base/ftdbgmem.c
    base/ftdebug.c
    base/ftfstype.c
    base/ftgasp.c
    base/ftgloadr.c
    base/ftglyph.c
    base/ftgxval.c
    base/ftinit.c
    base/ftlcdfil.c
    base/ftmm.c
    base/ftobjs.c
    base/ftotval.c
    base/ftoutln.c
    base/ftpatent.c
    base/ftpfr.c
    base/ftpic.c
    base/ftrfork.c
    base/ftsnames.c
    base/ftstream.c
    base/ftstroke.c
    base/ftsynth.c
    base/ftsystem.c
    base/fttrigon.c
    base/fttype1.c
    base/ftutil.c
    base/ftwinfnt.c
    base/ftxf86.c
    bdf/bdfdrivr.c
    bdf/bdflib.c
    cache/ftcbasic.c
    cache/ftccache.c
    cache/ftccmap.c
    cache/ftcglyph.c
    cache/ftcimage.c
    cache/ftcmanag.c
    cache/ftcmru.c
    cache/ftcsbits.c
    cff/cffcmap.c
    cff/cffdrivr.c
    cff/cffgload.c
    cff/cffload.c
    cff/cffobjs.c
    cff/cffparse.c
    cff/cffpic.c
    cid/cidgload.c
    cid/cidload.c
    cid/cidobjs.c
    cid/cidparse.c
    cid/cidriver.c
    gxvalid/gxvalid.c
    gxvalid/gxvbsln.c
    gxvalid/gxvcommn.c
    gxvalid/gxvfeat.c
    gxvalid/gxvjust.c
    gxvalid/gxvkern.c
    gxvalid/gxvlcar.c
    gxvalid/gxvmort.c
    gxvalid/gxvmort0.c
    gxvalid/gxvmort1.c
    gxvalid/gxvmort2.c
    gxvalid/gxvmort4.c
    gxvalid/gxvmort5.c
    gxvalid/gxvmorx.c
    gxvalid/gxvmorx0.c
    gxvalid/gxvmorx1.c
    gxvalid/gxvmorx2.c
    gxvalid/gxvmorx4.c
    gxvalid/gxvmorx5.c
    gxvalid/gxvopbd.c
    gxvalid/gxvprop.c
    gxvalid/gxvtrak.c
    gzip/adler32.c
    gzip/ftgzip.c
    gzip/infblock.c
    gzip/infcodes.c
    gzip/inflate.c
    gzip/inftrees.c
    gzip/infutil.c
    gzip/zutil.c
    lzw/ftlzw.c
    otvalid/otvalid.c
    otvalid/otvbase.c
    otvalid/otvcommn.c
    otvalid/otvgdef.c
    otvalid/otvgpos.c
    otvalid/otvgsub.c
    otvalid/otvjstf.c
    otvalid/otvmath.c
    pcf/pcfdrivr.c
    pcf/pcfread.c
    pcf/pcfutil.c
    pfr/pfrcmap.c
    pfr/pfrdrivr.c
    pfr/pfrgload.c
    pfr/pfrload.c
    pfr/pfrobjs.c
    pfr/pfrsbit.c
    psaux/afmparse.c
    psaux/psauxmod.c
    psaux/psconv.c
    psaux/psobjs.c
    psaux/t1cmap.c
    psaux/t1decode.c
    pshinter/pshalgo.c
    pshinter/pshglob.c
    pshinter/pshmod.c
    pshinter/pshpic.c
    pshinter/pshrec.c
    psnames/psmodule.c
    psnames/pspic.c
    raster/ftraster.c
    raster/ftrend1.c
    raster/rastpic.c
    sfnt/sfdriver.c
    sfnt/sfntpic.c
    sfnt/sfobjs.c
    sfnt/ttbdf.c
    sfnt/ttcmap.c
    sfnt/ttkern.c
    sfnt/ttload.c
    sfnt/ttmtx.c
    sfnt/ttpost.c
    sfnt/ttsbit.c
    smooth/ftgrays.c
    smooth/ftsmooth.c
    smooth/ftspic.c
    truetype/ttdriver.c
    truetype/ttgload.c
    truetype/ttgxvar.c
    truetype/ttinterp.c
    truetype/ttobjs.c
    truetype/ttpic.c
    truetype/ttpload.c
    type1/t1afm.c
    type1/t1driver.c
    type1/t1gload.c
    type1/t1load.c
    type1/t1objs.c
    type1/t1parse.c
    type42/t42drivr.c
    type42/t42objs.c
    type42/t42parse.c
    winfonts/winfnt.c
""")]
libfreetype = env.Library(['freetype'], LIBFREETYPE)

LIBREGAL = Split("""
    deps/regal/src/glu/libutil/mipmap.c
    deps/regal/src/glu/libutil/error.c
    deps/regal/src/glu/libutil/glue.c
    
    deps/regal/src/regal/RegalHelper.cpp    
    deps/regal/src/regal/Regal.cpp
    deps/regal/src/regal/RegalBreak.cpp
    deps/regal/src/regal/RegalLog.cpp
    deps/regal/src/regal/RegalCacheShader.cpp
    deps/regal/src/regal/RegalCacheTexture.cpp
    deps/regal/src/regal/RegalDispatch.cpp
    deps/regal/src/regal/RegalDispatchLog.cpp
    deps/regal/src/regal/RegalUtil.cpp
    deps/regal/src/regal/RegalInit.cpp
    deps/regal/src/regal/RegalToken.cpp
""")
regalenv = env.Clone()
regalenv.Append(
    CPPDEFINES=['REGAL_NO_PNG'],
    CPPPATH=[
        '#/deps/regal/src/glu/include',
        '#/deps/regal/include',
        '#/deps/regal/src/lookup3',
        '#/deps/regal/src/boost'])
libregal = regalenv.Library(['regal'], LIBREGAL)

SOURCES = Split("""
    deps/SDL_rwops.c
    deps/SDL_malloc.c
    deps/SDL_error.c
    deps/SDL_string.c
    
    AstroMenaceSource/Shims.cpp
    AstroMenaceSource/Core/Camera/Camera.cpp
    AstroMenaceSource/Core/Camera/CameraMath.cpp
    AstroMenaceSource/Core/CollisionDetection/AABB.cpp
    AstroMenaceSource/Core/CollisionDetection/CommonMath.cpp
    AstroMenaceSource/Core/CollisionDetection/OBB.cpp
    AstroMenaceSource/Core/CollisionDetection/Sphere.cpp
    AstroMenaceSource/Core/Font/Font.cpp
    AstroMenaceSource/Core/Font/FontManager.cpp
    AstroMenaceSource/Core/Light/Light.cpp
    AstroMenaceSource/Core/Light/LightManager.cpp
    AstroMenaceSource/Core/Math/Math.cpp
    AstroMenaceSource/Core/Math/Matrix33.cpp
    AstroMenaceSource/Core/Math/Matrix44.cpp
    AstroMenaceSource/Core/Model3D/Model3D.cpp
    AstroMenaceSource/Core/Model3D/Model3DManager.cpp
    AstroMenaceSource/Core/Model3D/VW3D.cpp
    AstroMenaceSource/Core/ParticleSystem/Particle.cpp
    AstroMenaceSource/Core/ParticleSystem/ParticleSystem.cpp
    AstroMenaceSource/Core/ParticleSystem/ParticleSystemManager.cpp
    AstroMenaceSource/Core/ParticleSystem2D/Particle2D.cpp
    AstroMenaceSource/Core/ParticleSystem2D/ParticleSystem2D.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Draw2D.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Draw3D.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_FBO.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_GLSL.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Light.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Main.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Matrix.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_OcclusionQuery.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_Texture.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_VAO.cpp
    AstroMenaceSource/Core/RendererInterface/OGL_VBO.cpp
    AstroMenaceSource/Core/RendererInterface/RI_Int.cpp
    AstroMenaceSource/Core/Sound/Buffer.cpp
    AstroMenaceSource/Core/Sound/Music.cpp
    AstroMenaceSource/Core/Sound/Sound.cpp
    AstroMenaceSource/Core/Sound/SoundManager.cpp
    AstroMenaceSource/Core/System/Keyboard.cpp
    AstroMenaceSource/Core/System/Languages/de.cpp
    AstroMenaceSource/Core/System/Languages/en.cpp
    AstroMenaceSource/Core/System/Languages/ru.cpp
    AstroMenaceSource/Core/System/Mouse.cpp
    AstroMenaceSource/Core/System/System.cpp
    AstroMenaceSource/Core/System/Timer.cpp
    AstroMenaceSource/Core/Text/Text.cpp
    AstroMenaceSource/Core/Texture/Texture.cpp
    AstroMenaceSource/Core/Texture/Texture_JPG.cpp
    AstroMenaceSource/Core/Texture/Texture_PNG.cpp
    AstroMenaceSource/Core/Texture/Texture_TGA.cpp
    AstroMenaceSource/Core/Texture/TextureManager.cpp
    AstroMenaceSource/Core/VirtualFileSystem/Haff.cpp
    AstroMenaceSource/Core/VirtualFileSystem/RLE.cpp
    AstroMenaceSource/Core/VirtualFileSystem/VFS.cpp
    AstroMenaceSource/Core/XML/XML.cpp
    AstroMenaceSource/Game/Game.cpp
    AstroMenaceSource/Game/Game_Camera.cpp
    AstroMenaceSource/Game/Game_Mission.cpp
    AstroMenaceSource/Game/Game_PlayerShip.cpp
    AstroMenaceSource/Game/Game_WeaponSlot.cpp
    AstroMenaceSource/GraphicFX/GameLvlText/GameLvlText.cpp
    AstroMenaceSource/GraphicFX/GameLvlText/GameLvlTextManager.cpp
    AstroMenaceSource/GraphicFX/ShadowMap.cpp
    AstroMenaceSource/GraphicFX/SkyBox.cpp
    AstroMenaceSource/GraphicFX/SpaceStars/SpaceStars.cpp
    AstroMenaceSource/GraphicFX/SpaceStars/Star.cpp
    AstroMenaceSource/GraphicFX/StarSystem.cpp
    AstroMenaceSource/Loading.cpp
    AstroMenaceSource/Loop_audio.cpp
    AstroMenaceSource/Loop_proc.cpp
    AstroMenaceSource/Main.cpp
    AstroMenaceSource/MainFS2VFS.cpp
    AstroMenaceSource/Menu/Button.cpp
    AstroMenaceSource/Menu/Dialog.cpp
    AstroMenaceSource/Menu/Menu.cpp
    AstroMenaceSource/Menu/Menu_ConfControl.cpp
    AstroMenaceSource/Menu/Menu_Credits.cpp
    AstroMenaceSource/Menu/Menu_Difficulty.cpp
    AstroMenaceSource/Menu/Menu_Information.cpp
    AstroMenaceSource/Menu/Menu_Interface.cpp
    AstroMenaceSource/Menu/Menu_Mission.cpp
    AstroMenaceSource/Menu/Menu_Options.cpp
    AstroMenaceSource/Menu/Menu_OptionsAdv.cpp
    AstroMenaceSource/Menu/Menu_Profile.cpp
    AstroMenaceSource/Menu/Menu_TopScores.cpp
    AstroMenaceSource/Menu/Menu_Workshop.cpp
    AstroMenaceSource/Menu/Menu_Workshop_Shipyard.cpp
    AstroMenaceSource/Menu/Menu_Workshop_Weaponry.cpp
    AstroMenaceSource/Menu/Menu_Workshop_Workshop.cpp
    AstroMenaceSource/Object3D/AI.cpp
    AstroMenaceSource/Object3D/Explosion/BulletExplosion/BulletExplosion.cpp
    AstroMenaceSource/Object3D/Explosion/Explosion.cpp
    AstroMenaceSource/Object3D/Explosion/ExplosionGFX.cpp
    AstroMenaceSource/Object3D/Explosion/ExplosionManager.cpp
    AstroMenaceSource/Object3D/Explosion/GroundExplosion/GroundExplosion.cpp
    AstroMenaceSource/Object3D/Explosion/SpaceExplosion/SpaceExplosion.cpp
    AstroMenaceSource/Object3D/GroundObject/Building/Building.cpp
    AstroMenaceSource/Object3D/GroundObject/GroundObject.cpp
    AstroMenaceSource/Object3D/GroundObject/GroundObjectManager.cpp
    AstroMenaceSource/Object3D/GroundObject/MilitaryBuilding/MilitaryBuilding.cpp
    AstroMenaceSource/Object3D/GroundObject/Tracked/Tracked.cpp
    AstroMenaceSource/Object3D/GroundObject/Wheeled/Wheeled.cpp
    AstroMenaceSource/Object3D/Object3D.cpp
    AstroMenaceSource/Object3D/Object3DCollision.cpp
    AstroMenaceSource/Object3D/Object3DCollisionMath.cpp
    AstroMenaceSource/Object3D/Object3DFunctions.cpp
    AstroMenaceSource/Object3D/Object3DManager.cpp
    AstroMenaceSource/Object3D/Projectile/Projectile.cpp
    AstroMenaceSource/Object3D/Projectile/ProjectileGFX.cpp
    AstroMenaceSource/Object3D/Projectile/ProjectileManager.cpp
    AstroMenaceSource/Object3D/SpaceObject/Asteroid/Asteroid.cpp
    AstroMenaceSource/Object3D/SpaceObject/BasePart/BasePart.cpp
    AstroMenaceSource/Object3D/SpaceObject/BigAsteroid/BigAsteroid.cpp
    AstroMenaceSource/Object3D/SpaceObject/Planet/Planet.cpp
    AstroMenaceSource/Object3D/SpaceObject/ShipPart/ShipPart.cpp
    AstroMenaceSource/Object3D/SpaceObject/SpaceObject.cpp
    AstroMenaceSource/Object3D/SpaceObject/SpaceObjectGFX.cpp
    AstroMenaceSource/Object3D/SpaceObject/SpaceObjectManager.cpp
    AstroMenaceSource/Object3D/SpaceShip/AlienSpaceFighter/AlienSpaceFighter.cpp
    AstroMenaceSource/Object3D/SpaceShip/AlienSpaceFighter/AlienSpaceFighterEngine.cpp
    AstroMenaceSource/Object3D/SpaceShip/AlienSpaceMotherShip/AlienSpaceMotherShip.cpp
    AstroMenaceSource/Object3D/SpaceShip/AlienSpaceMotherShip/AlienSpaceMotherShipEngine.cpp
    AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighter.cpp
    AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterArmour.cpp
    AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterEngine.cpp
    AstroMenaceSource/Object3D/SpaceShip/EarthSpaceFighter/EarthSpaceFighterWeapon.cpp
    AstroMenaceSource/Object3D/SpaceShip/PirateShip/PirateShip.cpp
    AstroMenaceSource/Object3D/SpaceShip/PirateShip/PirateShipEngine.cpp
    AstroMenaceSource/Object3D/SpaceShip/SpaceShip.cpp
    AstroMenaceSource/Object3D/SpaceShip/SpaceShipManager.cpp
    AstroMenaceSource/Object3D/Weapon/Weapon.cpp
    AstroMenaceSource/Object3D/Weapon/WeaponFunctions.cpp
    AstroMenaceSource/Object3D/Weapon/WeaponManager.cpp
    AstroMenaceSource/ScriptEngine/Script.cpp
    AstroMenaceSource/ScriptEngine/ScriptFunction.cpp
    AstroMenaceSource/ScriptEngine/Setup.cpp
""")
env = env.Clone()
env.Append(
    LINKFLAGS=['--preload-file', 'bin@/bin'])
env.Program('AstroMenace.html', SOURCES + libvorbis + libogg + libfreealut + libfreetype + libregal)
