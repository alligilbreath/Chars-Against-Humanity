# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.chars.Debug:
/Users/alligilbreath/Desktop/project6/project_6_example/bld/Debug/chars:
	/bin/rm -f /Users/alligilbreath/Desktop/project6/project_6_example/bld/Debug/chars


PostBuild.chars.Release:
/Users/alligilbreath/Desktop/project6/project_6_example/bld/Release/chars:
	/bin/rm -f /Users/alligilbreath/Desktop/project6/project_6_example/bld/Release/chars


PostBuild.chars.MinSizeRel:
/Users/alligilbreath/Desktop/project6/project_6_example/bld/MinSizeRel/chars:
	/bin/rm -f /Users/alligilbreath/Desktop/project6/project_6_example/bld/MinSizeRel/chars


PostBuild.chars.RelWithDebInfo:
/Users/alligilbreath/Desktop/project6/project_6_example/bld/RelWithDebInfo/chars:
	/bin/rm -f /Users/alligilbreath/Desktop/project6/project_6_example/bld/RelWithDebInfo/chars




# For each target create a dummy ruleso the target does not have to exist
