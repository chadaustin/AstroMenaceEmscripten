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

SOURCES = Split("""
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
env.Program('AstroMenace.html', SOURCES + libvorbis + libogg + libfreealut)
