"""postal_codes table added

Revision ID: 13673746db16
Revises: 23dd34bfaeaf
Create Date: 2015-04-27 17:08:52.775839

"""

# revision identifiers, used by Alembic.
revision = '13673746db16'
down_revision = '23dd34bfaeaf'

from alembic import op
import sqlalchemy as sa
import geoalchemy2 as ga
from sqlalchemy.dialects import postgresql


def upgrade():
    ### commands auto generated by Alembic - please adjust! ###
    op.create_table('postal_codes',
    sa.Column('admin_id', sa.BIGINT(), nullable=False),
    sa.Column('postal_code', sa.TEXT(), nullable=False),
    sa.ForeignKeyConstraint(['admin_id'], [u'georef.admin.id'], name=u'postal_codes_admin_id_fkey'),
    schema='georef'
    )
    ### end Alembic commands ###


def downgrade():
    ### commands auto generated by Alembic - please adjust! ###
    op.drop_table('postal_codes', schema='georef')
    ### end Alembic commands ###
